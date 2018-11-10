//
//  SphereLight.h
//  RayTracer
//
//  Created by Fernando Pedro Birra on 07/05/16.
//  Copyright © 2016 FCT/UNL. All rights reserved.
//

#ifndef SphereLight_h
#define SphereLight_h

#include "PointLight.h"

class SphereLight : public PointLight {
public:
    SphereLight(const Color &col=Color::white, const Vector3& pos = Vector3(), real r=1.0) : PointLight(col, pos), r(r) {};
    virtual ~SphereLight() {};
    
    virtual Color L(const Vector3 &pos, const Vector3 &dir) const;

    virtual Vector3 sampleDir(const Vector3 &from, real &tmax) const;
    
    virtual int samples() const { return 1+30*r*r*r; }
public:
    real r;
};


#endif /* SphereLight_h */
