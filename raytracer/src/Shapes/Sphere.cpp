//
//  Sphere.cpp
//  RayTracer
//
//  Created by Fernando Birra on 07/11/13.
//  Copyright (c) 2013 FCT/UNL. All rights reserved.
//
#include <math.h>

#include "Sphere.h"

Sphere::Sphere(const Vector3 &c, real r):c(c), r(r)
{
}

Sphere::~Sphere()
{
}

bool Sphere::intersects(const Ray &ray, real &t, Hit &h) const
{
    // compute a, b and c coefficients
    real a = ray.d.dot();              // a=d.d
    real b = 2 * ray.d.dot(ray.o);     // b=2(d.o)
    real c = ray.o.dot() - r*r;        // c=o.o-r*r
    
    real t0, t1;
    
    if(!quadratic(a,b,c,t0,t1))
        return false;
    
    // check if both points are out of ray's range
    if(t1 < ray.mint || t0 > ray.maxt)
        return false;
    
    if(t0<ray.mint) t=t1;
    else            t=t0;
    
    h.p = ray.position(t);
    h.n = (h.p - this->c);
    
    return true;
}

bool Sphere::intersects(const Ray &ray) const
{
    // compute a, b and c coefficients
    real a = ray.d.dot();              // a=d.d
    real b = 2 * ray.d.dot(ray.o);     // b=2(d.o)
    real c = ray.o.dot() - r*r;        // c=o.o-r*r
    
    real t0, t1;
    
    if(!quadratic(a,b,c,t0,t1))
        return false;
    
    // check if both points are out of ray's range
    if(t1 < ray.mint || t0 > ray.maxt)
        return false;
    
    return true;
}