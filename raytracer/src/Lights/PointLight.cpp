//
//  PointLight.cpp
//  RayTracer
//
//  Created by Fernando Pedro Birra on 07/05/16.
//  Copyright © 2016 FCT/UNL. All rights reserved.
//

#include "PointLight.h"

Vector3 PointLight::sampleDir(const Vector3 &from, real &tmax) const
{
    Vector3 l = pos-from;
    tmax = l.length();
    l.normalize();
    return l;
}

Color PointLight::L(const Vector3 &pos, const Vector3 &dir) const
{
    return col;
}
