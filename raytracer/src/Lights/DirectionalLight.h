//
//  DirectionalLight.hpp
//  RayTracer
//
//  Created by Fernando Pedro Birra on 07/05/16.
//  Copyright © 2016 FCT/UNL. All rights reserved.
//


#ifndef DirectionalLight_hpp
#define DirectionalLight_hpp

#include "Light.h"

class DirectionalLight : public Light {
public:
    DirectionalLight(): Light(), dir(0,-1,0) {};
    DirectionalLight(const Vector3 &dir) : Light(), dir(dir) { this->dir.normalize(); };
    DirectionalLight(const Color &col, const Vector3 &dir): Light(col), dir(dir) { this->dir.normalize(); }
    virtual ~DirectionalLight() {};
    
    virtual Color L(const Vector3 &pos, const Vector3 &dir) const;
    
    virtual Vector3 sampleDir(const Vector3 &from, real &tmax) const;
public:
    Vector3 dir;
};

#endif /* DirectionalLight_hpp */
