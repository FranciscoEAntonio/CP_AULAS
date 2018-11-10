//
//  TransformSeq.h
//  RayTracer
//
//  Created by Fernando Pedro Birra on 25/05/15.
//  Copyright (c) 2015 FCT/UNL. All rights reserved.
//

#ifndef __RayTracer__TransformSeq__
#define __RayTracer__TransformSeq__

#include <stdio.h>

#include "Transform.h"

class TransformSeq {
public:
    TransformSeq() : t(1.), tinv(1.) {};
    virtual ~TransformSeq() {};
    
    TransformSeq& addTranslation(real tx, real ty, real tz);
    TransformSeq& addScale(real sx, real sy, real sz);
    TransformSeq& addRotx(real angle);
    TransformSeq& addRoty(real angle);
    TransformSeq& addRotz(real angle);
    
    Vector3 applyToPoint(const Vector3 &v) const;
    Vector3 applyToVector(const Vector3 &v) const;
    Vector3 applyToNormal(const Vector3 &v) const;

    Vector3 applyInverseToPoint(const Vector3 &v) const;
    Vector3 applyInverseToVector(const Vector3 &v) const;
    Vector3 applyInverseToNormal(const Vector3 &v) const;
    
public:
    Transform t;
    Transform tinv;
    
private:
    void accumFromParts(const Transform &t, const Transform &tinv);
};

#endif /* defined(__RayTracer__TransformSeq__) */
