//
//  defines.cpp
//  RayTracer
//
//  Created by Fernando Pedro Birra on 07/05/16.
//  Copyright © 2016 FCT/UNL. All rights reserved.
//

#include <cmath>

#include "defines.h"

bool quadratic(real a, real b, real c, real &t0, real &t1)
{
    // compute discriminant
    real disc = b*b-4*a*c;
    
    //if discriminant is negative there are no real roots: ray misses sphere
    if(disc<0) return false;
    
    // compute q
    real distSqrt = sqrt(disc);
    real q;
    
    if(b<0) q = -0.5*(b - distSqrt);
    else    q = -0.5*(b + distSqrt);
    
    // compute t0 and t1
    t0 = q/a;
    t1 = c/q;
    
    // swap t0 and t1 if t0 is greater than t1
    if(t0>t1) { real temp = t0; t0 = t1; t1=temp; }
    
    return true;
}

bool inside(real v, real a, real b)
{
    return a <= v && v <= b;
}