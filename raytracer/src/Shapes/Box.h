//
//  Box.h
//  RayTracer
//
//  Created by Fernando Pedro Birra on 06/05/16.
//  Copyright © 2016 FCT/UNL. All rights reserved.
//

#ifndef Box_h
#define Box_h

#include "Primitive.h"

class Box : public Primitive {
    
public:
    Box();
    Box(const Vector3& min, const Vector3 &max);
    virtual ~Box();
    
    // Intersection tests
    virtual bool intersects(const Ray &r, real &t, Hit &h) const;
    virtual bool intersects(const Ray &r) const;
    
    //
    // Plane data members
    //
    
    // corners of the box
    Vector3 min, max;
};

#endif /* Box_h */
