//
//  Sphere.h
//  RayTracer
//
//  Created by Fernando Birra on 07/11/13.
//  Copyright (c) 2013 FCT/UNL. All rights reserved.
//

#ifndef __RayTracer__Sphere__
#define __RayTracer__Sphere__

#include "Primitive.h"

class Sphere : public Primitive {
    
public:
    Sphere(const Vector3& c=Vector3(0,0,0), real r=1.0);
    virtual ~Sphere();
    
    // Intersection tests
    virtual bool intersects(const Ray &r, real &t, Hit &h) const;
    virtual bool intersects(const Ray &r) const;

    //
    // Sphere data members
    //
    
    // center of the sphere
    Vector3 c;
    // radius of the sphere
    real r;
};

#endif /* defined(__RayTracer__Sphere__) */
