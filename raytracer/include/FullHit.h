//
//  FullHit.h
//  RayTracer
//
//  Created by Fernando Pedro Birra on 29/05/15.
//  Copyright (c) 2015 FCT/UNL. All rights reserved.
//

#ifndef __RayTracer__FullHit__
#define __RayTracer__FullHit__

#include "Hit.h"
#include "Vector3.h"
#include "TransformSeq.h"

class Instance;

class FullHit {
    
public:
    
    enum Direction { Outwards, Inwards };
    
    Hit h;
    Instance *i;
    Direction direction;
    
    FullHit(const Hit &h=Hit(), Instance *i=NULL) : h(h), i(i), direction(Outwards) {};
    virtual ~FullHit() {};
    
    void adjustHit(const Vector3 &raydir);
};

#endif /* defined(__RayTracer__FullHit__) */
