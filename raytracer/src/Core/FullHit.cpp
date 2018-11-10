//
//  FullHit.cpp
//  RayTracer
//
//  Created by Fernando Pedro Birra on 29/05/15.
//  Copyright (c) 2015 FCT/UNL. All rights reserved.
//

#include "FullHit.h"

void FullHit::adjustHit(const Vector3 &raydir)
{
    if(dot(h.n, raydir) > 0) {
        direction = FullHit::Inwards;
        h.n *= -1;
    }
    else {
        direction = FullHit::Outwards;
    }
    
    h.p += h.n * OFFSET_INT;
}