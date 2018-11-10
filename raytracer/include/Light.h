//
//  Light.h
//  RayTracer
//
//  Created by Fernando Pedro Birra on 25/05/15.
//  Copyright (c) 2015 FCT/UNL. All rights reserved.
//

#ifndef __RayTracer__Light__
#define __RayTracer__Light__

#include <stdio.h>

#include "Color.h"
#include "Vector3.h"

class Light {
  
public:
    Light(const Color &col = Color::white) : col(col) {};
    virtual ~Light() {};

    // Override this in subclasses
    // Returns a normalized vector pointing to the light source
    virtual Vector3 sampleDir(const Vector3 &from, real &tmax) const = 0; // Returns a direction pointing to the light
    
    // returns exitant radiance at point pos along direction dir
    virtual Color L(const Vector3 &pos, const Vector3 &dir) const = 0;
    
    virtual int samples() const { return 1; }
    
public:
    // Data members
    Color col;  // light's color

};


#endif /* defined(__RayTracer__Light__) */
