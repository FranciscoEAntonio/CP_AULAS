//
//  defines.h
//  RayTracer
//
//  Created by Fernando Birra on 05/11/13.
//  Copyright (c) 2013 FCT/UNL. All rights reserved.
//

#ifndef RayTracer_defines_h
#define RayTracer_defines_h

typedef double real;
const real INFINITE=1e30;
const real OFFSET_INT=1e-6;

#define MAX(a,b)    ((a)>(b)?(a):(b))
#define MIN(a,b)    ((a)<(b)?(a):(b))

bool quadratic(real a, real b, real c, real &t0, real &t1);
bool inside(real v, real a, real b);

#endif
