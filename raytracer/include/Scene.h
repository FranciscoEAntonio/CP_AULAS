//
//  Scene.h
//  RayTracer
//
//  Created by Fernando Birra on 08/11/13.
//  Copyright (c) 2013 FCT/UNL. All rights reserved.
//

#ifndef __RayTracer__Scene__
#define __RayTracer__Scene__

#include <iostream>
#include <vector>

#include "Instance.h"
#include "Light.h"

#define SCENE_DEFAULT_MAX_DEPTH 10

class Scene {
    
public:
    Scene() : maxDepth(SCENE_DEFAULT_MAX_DEPTH), background(0,0,0) {};
    virtual ~Scene();
    
    virtual void addInstance(Instance *obj);
    virtual void addLight(Light *light);
    
    virtual void setCameraPos(const Vector3 &eye);
    
    virtual void setBackground(const Color &background);
    virtual bool survives(const Ray &r) const;
    virtual Color traceRay(const Ray &r, int depth=0);
    
    Color getDiffusePlusSpecular(const Light &light, const FullHit &h) const;
    Color sampleLight(const Vector3 &P, const Light *light, Vector3 &L) const;
    bool getFirstHit(const Ray &r, real &t, FullHit &h) const;
    
    // data members
    int maxDepth;
    Color background;
    Vector3 eye;
    std::vector<Instance *> instances;
    std::vector<Light *> lights;
};

#endif /* defined(__RayTracer__Scene__) */
