//
//  Primitive.h
//  RayTracer
//
//  Created by Fernando Birra on 07/11/13.
//  Copyright (c) 2013 FCT/UNL. All rights reserved.
//
//  A primitive is an object supported by the ray tracer.
//  The core functionality is the ray-primitive intersection code.
//  All intersection tests are performed in local space by transforming
//  the ray to be tested from world space to local space (see Instance class)

#ifndef __RayTracer__Primitive__
#define __RayTracer__Primitive__

#include <iostream>

#include "Hit.h"
#include "Ray.h"
#include "Color.h"

class Primitive {

public:
    Primitive();
    virtual ~Primitive();
    
    // full intersection test. Returns the value of t at the intersection and extra
    // information in Hit.
    virtual bool intersects(const Ray &r, real &t, Hit &h) const = 0;
    // simpler intersection test. No need to compute point of intersection
    virtual bool intersects(const Ray &r) const = 0;
};

#endif /* defined(__RayTracer__Primitive__) */
