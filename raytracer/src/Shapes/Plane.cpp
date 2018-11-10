//
//  Plane.cpp
//  RayTracer
//
//  Created by Fernando Pedro Birra on 06/05/16.
//  Copyright © 2016 FCT/UNL. All rights reserved.
//

#include "Plane.h"

Plane::Plane(const Vector3 &n, real d):n(n), d(d)
{
    this->n.normalize();
}

Plane::Plane(const Vector3 &n, const Vector3 &p):n(n)
{
    // TO DO: Compute d from p
    this->n.normalize();
    
    d = - dot(p, this->n);
}

Plane::~Plane()
{
}

bool Plane::intersects(const Ray &ray, real &t, Hit &h) const
{
    real den = dot(ray.d, this->n);
    
    if(den == 0.0) return false;
    
    t = - (dot(ray.o, n) + d) / den;
    
    if (t<0) return false;
    
    h.p = ray.o + ray.d * t;
    h.n = n;
    
    return true;
}

bool Plane::intersects(const Ray &ray) const
{
    real den = dot(ray.d, this->n);
    
    if(den == 0.0) return false;
    
    real t = - (dot(ray.o, n) + d) / den;
    
    if (t<0) return false;
    
    return true;
}