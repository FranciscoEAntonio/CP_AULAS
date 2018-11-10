//
//  Plane.h
//  RayTracer
//
//  Created by Fernando Pedro Birra on 06/05/16.
//  Copyright © 2016 FCT/UNL. All rights reserved.
//

#ifndef Plane_h
#define Plane_h

#include "Primitive.h"

class Plane : public Primitive {
    
public:
    Plane(const Vector3& n=Vector3(0,1,0), real d=0.0);
    Plane(const Vector3& n, const Vector3 &p);
    virtual ~Plane();
    
    // Intersection tests
    virtual bool intersects(const Ray &r, real &t, Hit &h) const;
    virtual bool intersects(const Ray &r) const;
    
    //
    // Plane data members
    //
    
    // normal vector to the plane
    Vector3 n;
    // distance from origin
    real d;
};

#endif /* Plane_h */
