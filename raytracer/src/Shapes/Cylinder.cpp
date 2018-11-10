//
//  Cylinder.cpp
//  RayTracer
//
//  Created by Fernando Pedro Birra on 07/05/16.
//  Copyright © 2016 FCT/UNL. All rights reserved.
//
#include <cmath>

#include "Cylinder.h"

Cylinder::Cylinder(real r, real h): r(r), h(h)
{
}

Cylinder::~Cylinder()
{
}

bool Cylinder::intersects(const Ray &ray, real &t, Hit &h) const
{
    real A = ray.d.x * ray.d.x + ray.d.z * ray.d.z;
    real B = 2 * (ray.o.x * ray.d.x + ray.o.z * ray.d.z);
    real C = ray.o.x * ray.o.x + ray.o.z * ray.o.z - r*r;
    
    real t0, t1;
    if(!quadratic(A, B, C, t0, t1))
        return false;
    
    // Both intersections out of ray's range
    if(t1 < ray.mint || t0 > ray.maxt) return false;
    
    // Check if t0 is behind
    if(t0 > ray.mint)
        t = t0;
    else t = t1;
    
    Vector3 p = ray.position(t);
    
    if(p.y > 0.5 || p.y < -0.5 ) {
        
        if( t==t1) return false;
        
        t = t1;
        p = ray.position(t);
        
        if(p.y > 0.5 || p.y < -0.5)
            return false;
    }
    
    h.p = ray.position(t);
    h.n = Vector3(h.p.x, 0, h.p.z);
    h.n.normalize().away(ray.d);
    
    return true;
}

bool Cylinder::intersects(const Ray &ray) const
{
    real A = ray.d.x * ray.d.x + ray.d.z * ray.d.z;
    real B = 2 * (ray.o.x * ray.d.x + ray.o.z * ray.d.z);
    real C = ray.o.x * ray.o.x + ray.o.z * ray.o.z - r*r;
    
    real t, t0, t1;
    if(!quadratic(A, B, C, t0, t1))
        return false;
    
    // Both intersections out of ray's range
    if(t1 < ray.mint || t0 > ray.maxt) return false;
    
    // Check if t0 is behind
    if(t0 > ray.mint)
        t = t0;
    else t = t1;
    
    Vector3 p = ray.position(t);
    
    if(p.y > 0.5 || p.y < -0.5 ) {
        
        if( t==t1) return false;
        
        t = t1;
        p = ray.position(t);
        
        if(p.y > 0.5 || p.y < -0.5)
            return false;
    }
        
    return true;
}