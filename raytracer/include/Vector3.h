//
//  P3d.h
//  RayTracer
//
//  Created by Fernando Birra on 05/11/13.
//  Copyright (c) 2013 FCT/UNL. All rights reserved.
//

#ifndef __RayTracer__P3d__
#define __RayTracer__P3d__

#include <iostream>

#include "defines.h"

class Vector3 {

public:
    
    // returns a normalized random direction
    static Vector3 randomDir();
    
    // Null vector
    Vector3();
    
    // Copy constructor
    Vector3(const Vector3& other);
    
    // Constructor from component values
    Vector3(real x, real y, real z);
    
    // Destructor
    virtual ~Vector3();
    
    //
    // various selectors
    //
    
    // length of a vector
    real length() const;
    
    // internal (dot) product of vector with itself
    real dot() const;
    
    // internal (dot) product with (an)other vector
    real dot(const Vector3& other) const;
    
    // cross product with (an)other vector
    Vector3 cross(const Vector3 &other) const;
    
    // returns a reflected version of this vector. The angle between this and N
    // is the same as the angle between the returned vector and N. All vectors lie
    // in the same plane
    Vector3 reflected(const Vector3 &N) const;
    
    Vector3 refracted(const Vector3 &N, real nr) const;
    
    bool inside(const Vector3 &min, const Vector3 &max) const;
    
    //
    // various modifiers
    //
    
    // scales a vector y some real value ammount
    Vector3& scale(real s);
    
    // normalizes a vector (unit length)
    Vector3& normalize();
    
    // flip a vector if it is pointing away from a give vector
    Vector3& towards(const Vector3 &other);
    
    // flip a vector if it is not pointing away from a give vector
    Vector3& away(const Vector3 &other);
    
    // The data storage of a vector
    union {
        struct { real  x, y, z; };
        real  v[3];
    };
};

// returns the dot product between two vectors
real dot(const Vector3 &a, const Vector3 &b);

// returns the cross product between two vectors
Vector3 cross(const Vector3 &a, const Vector3 &b);

// The unary minus operator. Returns the simmetric vector
Vector3 operator -(const Vector3 &a);

// vector addition
Vector3 operator +(const Vector3 &a, const Vector3& b);
// vector subtraction
Vector3 operator -(const Vector3 &a, const Vector3& b);
// vector-scalar multiplication
Vector3 operator *(const Vector3 &a, real s);
// scalar-vector multiplication
Vector3 operator *(real s, const Vector3 &a);

// a = a + b
Vector3& operator +=(Vector3 &a, const Vector3 &b);
// a = a - b
Vector3& operator -=(Vector3 &a, const Vector3 &b);
// a = a * s (scale)
Vector3& operator *=(Vector3 &a, real s);

// dumps a vector to an output stream
std::ostream& operator << (std::ostream &os, const Vector3 &v);

#endif /* defined(__RayTracer__P3d__) */

