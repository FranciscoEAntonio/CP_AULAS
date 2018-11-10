//
//  DirectionalLight.cpp
//  RayTracer
//
//  Created by Fernando Pedro Birra on 07/05/16.
//  Copyright © 2016 FCT/UNL. All rights reserved.
//

#include "DirectionalLight.h"

Vector3 DirectionalLight::sampleDir(const Vector3 &from, real &tmax) const
{
    tmax = INFINITE;
    return - dir;
}

Color DirectionalLight::L(const Vector3 &pos, const Vector3 &dir) const
{
    return col;
}
