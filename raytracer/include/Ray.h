//
//  Ray.h
//  RayTracer
//
//  Created by Fernando Birra on 07/11/13.
//  Copyright (c) 2013 FCT/UNL. All rights reserved.
//

#ifndef __RayTracer__Ray__
#define __RayTracer__Ray__

#include <iostream>

#include "Vector3.h"
#include "TransformSeq.h"

class Ray {
public:
    Ray(const Vector3 &o, const Vector3 &d, real mint=0, real maxt=INFINITE);
    virtual ~Ray();
  
    // Transforms a ray from world space into local (primitive) space
    Ray worldToLocal(const TransformSeq &ts) const;
    
    // Returns the reflected ray according to some direction n
    Ray reflected(const Vector3 &p, const Vector3 &n) const;
    
    // Returns the refracted ray according to some direction n
    Ray refracted(const Vector3 &p, const Vector3 &n, real nr) const;
    
    // Compute ray positon for a given t value
    Vector3 position(real t) const;
    
    // Ray data members
    Vector3 o, d;   // Origin and direction
    real mint, maxt;
};

// Outputs a ray into an output stream
std::ostream& operator << (std::ostream &os, const Ray &r);

#endif /* defined(__RayTracer__Ray__) */
