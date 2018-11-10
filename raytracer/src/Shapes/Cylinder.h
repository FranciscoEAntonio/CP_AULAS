//
//  Cylinder.h
//  RayTracer
//
//  Created by Fernando Pedro Birra on 07/05/16.
//  Copyright © 2016 FCT/UNL. All rights reserved.
//

#ifndef Cylinder_h
#define Cylinder_h

#include "Primitive.h"

class Cylinder : public Primitive {
    
public:
    Cylinder(real r=1.0, real h=1.0);
    virtual ~Cylinder();
    
    // Intersection tests
    virtual bool intersects(const Ray &r, real &t, Hit &h) const;
    virtual bool intersects(const Ray &r) const;
    
    //
    // Cylinder data members
    //
    
    // radius of the cylinder
    real r;
    // height (along y) of the cylinder
    real h;
};

#endif /* Cylinder_h */
