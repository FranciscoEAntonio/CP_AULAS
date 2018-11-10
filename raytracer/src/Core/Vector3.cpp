//
//  P3d.cpp
//  RayTracer
//
//  Created by Fernando Birra on 05/11/13.
//  Copyright (c) 2013 FCT/UNL. All rights reserved.
//
#include <cmath>
#include <stdlib.h>

#include "Vector3.h"

Vector3::Vector3() : x(0), y(0), z(0)
{
}

Vector3::Vector3(const Vector3 &other): x(other.x), y(other.y), z(other.z)
{
}

Vector3::Vector3(real x, real y, real z): x(x), y(y), z(z)
{
}

Vector3::~Vector3()
{
}

// Selectors
real Vector3::length() const
{
    return ::sqrt(dot());
}

real Vector3::dot() const
{
    return x*x + y*y + z*z;
}

real Vector3::dot(const Vector3& other) const
{
    return x*other.x + y*other.y + z*other.z;
}

Vector3 Vector3::cross(const Vector3 &other) const
{
    Vector3 res;
    
    res.x = y * other.z - z * other.y;
    res.y = z * other.x - x * other.z;
    res.z = x * other.y - y * other.x;
    
    return res;
}

Vector3 Vector3::reflected(const Vector3 &N) const
{
    Vector3 L = *this;
    
    return 2 * N.dot(L) * N - L;
}

Vector3 Vector3::refracted(const Vector3 &N, real nr) const
{
    real ndoti = ::dot(N,-(*this));
    real disc = 1 - nr*nr * (1-ndoti*ndoti);
    
    if(disc < 0) {
        return Vector3(0,0,0);
    }
    real factor = nr * ndoti - ::sqrt(disc);
    
    Vector3 res = factor * N + nr * (*this);
    return res;
}

bool Vector3::inside(const Vector3 &min, const Vector3 &max) const
{
    return ::inside(this->x, min.x, max.x) && ::inside(this->y, min.y, max.y) && ::inside(this->z, min.z, max.z);
}

// Modifiers
Vector3& Vector3::scale(real s)
{
    x*=s; y*=s; z*=s;
    return *this;
}

Vector3& Vector3::normalize()
{
    real len = ::sqrt(dot()); x/=len; y/=len; z/=len; return *this;
}

Vector3& Vector3::towards(const Vector3 &other)
{
    if(this->dot(other) < 0)
        *this *= -1;
    return *this;
}

Vector3& Vector3::away(const Vector3 &other)
{
    if(this->dot(other) > 0)
        *this *= -1;
    return *this;
}

real dot(const Vector3 &a, const Vector3 &b)
{
    return a.dot(b);
}

Vector3 cross(const Vector3 &a, const Vector3 &b)
{
    return a.cross(b);
}

//Operators
Vector3 operator -(const Vector3 &a)
{
    return Vector3(-a.x, -a.y, -a.z);
}

Vector3 operator +(const Vector3 &a, const Vector3 &b)
{
    return Vector3(a.x+b.x, a.y+b.y, a.z+b.z);
}

Vector3 operator -(const Vector3 &a, const Vector3 &b)
{
    return Vector3(a.x-b.x, a.y-b.y, a.z-b.z);
}

Vector3 operator *(real s, const Vector3 &a)
{
    return Vector3(a.x*s, a.y*s, a.z*s);
}

Vector3 operator *(const Vector3 &a, real s)
{
    return Vector3(a.x*s, a.y*s, a.z*s);
}

Vector3& operator +=(Vector3 &a, const Vector3 &b)
{
    a.x += b.x;
    a.y += b.y;
    a.z += b.z;
    return a;
}

Vector3& operator -=(Vector3 &a, const Vector3 &b)
{
    a.x -= b.x;
    a.y -= b.y;
    a.z -= b.z;
    return a;
}

Vector3& operator *=(Vector3 &a, real s)
{
    a.x *= s; a.y *= s; a.z *= s;
    return a;
}

std::ostream& operator << (std::ostream &os, const Vector3 &v)
{
    os << "(x=" << v.x << " y=" << v.y << " z=" << v.z << ")" << std::endl;
    return os;
}

Vector3 Vector3::randomDir()
{
    real r = RAND_MAX/2.0;
    real x = (rand()-r) / (real) r;
    real y = (rand()-r) / (real) r;
    real z = (rand()-r) / (real) r;
    
    Vector3 res(x,y,z);
    res.normalize();
    
    return res;
}
