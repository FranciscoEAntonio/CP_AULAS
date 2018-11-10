//
//  Hit.cpp
//  RayTracer
//
//  Created by Fernando Pedro Birra on 29/05/15.
//  Copyright (c) 2015 FCT/UNL. All rights reserved.
//

#include "Hit.h"

Hit Hit::localToWorld(const TransformSeq &ts) const
{
    Hit h;
    
    h.p = ts.applyToPoint(this->p);
    h.n = ts.applyToNormal(this->n);
    h.n.normalize();
    
    return h;
}
