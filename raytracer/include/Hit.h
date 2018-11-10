//
//  Hit.h
//  RayTracer
//
//  Created by Fernando Pedro Birra on 29/05/15.
//  Copyright (c) 2015 FCT/UNL. All rights reserved.
//

#ifndef __RayTracer__Hit__
#define __RayTracer__Hit__

#include "Vector3.h"
#include "TransformSeq.h"

class Hit {
public:
    Vector3 p;
    Vector3 n;
    
    Hit() : p(), n() {};
    Hit(const Vector3 &p, const Vector3 &n) : p(p), n(n) {};
    virtual ~Hit() {};
    
    Hit localToWorld(const TransformSeq &ts) const;
};

#endif /* defined(__RayTracer__Hit__) */
