//
//  AreaLight.h
//  RayTracer
//
//  Created by Fernando Pedro Birra on 25/05/15.
//  Copyright (c) 2015 FCT/UNL. All rights reserved.
//

#ifndef __RayTracer__AreaLight__
#define __RayTracer__AreaLight__

#include <stdio.h>

#include "Color.h"
#include "Vector3.h"

class AreaLight : public Light {
  
public:
    AreaLight(const Color &col = Color::white) : Light(col) {};
    virtual ~AreaLight() {};

    virtual int samples() const = 0;
};


#endif /* defined(__RayTracer__AreaLight__) */
