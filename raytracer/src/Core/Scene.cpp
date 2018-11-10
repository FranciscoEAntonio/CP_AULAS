//
//  Scene.cpp
//  RayTracer
//
//  Created by Fernando Birra on 08/11/13.
//  Copyright (c) 2013 FCT/UNL. All rights reserved.
//
#include <math.h>

#include "Scene.h"

Scene::~Scene()
{
    // Delete all objects stored inside arrays

    // Delete instances
    for(std::vector<Instance *>::iterator ii = instances.begin(); ii!=instances.end(); ii++)
    {
        delete *ii;
    }
    
    // Delete lights
    for(std::vector<Light*>::iterator il = lights.begin(); il!=lights.end(); il++)
    {
        delete *il;
    }
}

void Scene::setCameraPos(const Vector3 &eye)
{
    this->eye = eye;
}

void Scene::setBackground(const Color &background)
{
    this->background = background;
}

void Scene::addInstance(Instance *obj)
{
    instances.push_back(obj);
}

void Scene::addLight(Light *light)
{
    lights.push_back(light);
}

bool Scene::survives(const Ray& rl) const
{
    for(std::vector<Instance *>::const_iterator it=instances.begin(); it!=instances.end(); it++)
    {
        if((*it)->intersects(rl)) {
            return false;
        }
    }
    return true;
}

bool Scene::getFirstHit(const Ray &r, real &t, FullHit &h) const
{
    real tmin = INFINITE;

    // process each primitive instace
    for(std::vector<Instance *>::const_iterator it=instances.begin(); it!=instances.end(); it++)
    {
        FullHit hit;
        real t=INFINITE;
        Instance *ins = *it;
        if(ins->intersects(r, t, hit)) {
            if(t < tmin) {
                // This intersection is closest to the ray origin
                tmin = t;
                h = hit;
            }
        }
    }

    return tmin != INFINITE;
}

Color Scene::sampleLight(const Vector3 &P, const Light *light, Vector3 &L) const
{
    int count=0, n = light->samples();
    real strength;
    
    for(int i=0; i<n; i++) {
        
        // Get light direction
        real tmax;
        L = light->sampleDir(P, tmax);
        
        // Create a light ray
        Ray rl(P, L, 0, tmax);
        
        // Test for intersection
        if (this->survives(rl)) count++;
    }
    strength = count / (real) n;
    
    // Return radiance towards P scaled by strength (Not physically correct)
    Color res = light->L(P, L) * strength;

    return res;
}

Color Scene::getDiffusePlusSpecular(const Light &light, const FullHit &h) const
{
    Color res = Color::black;
    real ndotl, rdotv;
    Vector3 L;
    
    Vector3 P = h.h.p, N = h.h.n;
    Color lc = sampleLight(P, &light, L);
    const Material &m = h.i->m;
    
    if(lc != Color::black) {
        
        // Compute direction of reflected light
        Vector3 R = L.reflected(N);
        
        // Compute direction to viewer
        Vector3 V = this->eye - P; V.normalize();
        
        ndotl = MAX(0, dot(N, L)); rdotv = MAX(0, dot(R, V));
    }
    else {
        ndotl = 0; rdotv = 0;
    }
    
    res += m.kd * lc * ndotl;
    res += m.ks * lc * ::pow(rdotv, m.ns);
    
    return res;
}

Color Scene::traceRay(const Ray &r, int depth)
{
    real tmin;
    FullHit h;
 
    if(depth == maxDepth) return Color::black;
    
    if(getFirstHit(r, tmin, h)) // We have a hit
    {
        Color diffuse, specular, reflected, transmitted = Color::black;
        Vector3 P = h.h.p, N = h.h.n;
        const Material &m = h.i->m;
        Color dPs;
        
        for(std::vector<Light *>::iterator il=lights.begin(); il!=lights.end(); il++)
            dPs += getDiffusePlusSpecular(*(*il), h);

        
        if( h.i->m.isReflective ) {
            Ray rr = r.reflected(P, N); rr.d *= -1;
            reflected = this->traceRay(rr, depth + 1) * m.kr;
        }   
        
        if( h.i->m.isTransmissive) {
            real nr = h.direction == FullHit::Outwards ? 1/m.nt : m.nt;
            Ray rr = r.refracted(P - 2*N*OFFSET_INT, N, nr);
            if(r.d.length()>0) // Check for TIR
                transmitted = this->traceRay(rr, depth + 1) * m.kt;
        }
        //return m.ka + diffuse + specular + reflected + transmitted;
        return m.ka + dPs + reflected + transmitted;
    }
    return background;
}