//
//  PointLight.h
//  RayTracer
//
//  Created by Fernando Pedro Birra on 07/05/16.
//  Copyright © 2016 FCT/UNL. All rights reserved.
//

#ifndef PointLight_h
#define PointLight_h

#include "Light.h"

class PointLight : public Light {
public:
    PointLight(const Color &col = Color::white, const Vector3 &pos=Vector3()) : Light(col), pos(pos) {};
    virtual ~PointLight() {};
    
    virtual Color L(const Vector3 &pos, const Vector3 &dir) const;
    
    virtual Vector3 sampleDir(const Vector3 &from, real &tmax) const;

public:
    Vector3 pos;
};


#endif /* PointLight_h */
