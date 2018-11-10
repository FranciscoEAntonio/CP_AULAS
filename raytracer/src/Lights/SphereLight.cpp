//
//  SphereLight.cpp
//  RayTracer
//
//  Created by Fernando Pedro Birra on 07/05/16.
//  Copyright © 2016 FCT/UNL. All rights reserved.
//

#include "SphereLight.h"

Vector3 SphereLight::sampleDir(const Vector3 &from, real &tmax) const
{
    // Generate a random point on the sphere surface
    Vector3 pp = pos + this->r * Vector3::randomDir();
    
    Vector3 l = pp-from;
    tmax = l.length();
    l.normalize();
    return l;
}

Color SphereLight::L(const Vector3 &pos, const Vector3 &dir) const
{
    return col;
}