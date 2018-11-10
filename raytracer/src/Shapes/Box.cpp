//
//  Box.cpp
//  RayTracer
//
//  Created by Fernando Pedro Birra on 06/05/16.
//  Copyright © 2016 FCT/UNL. All rights reserved.
//

#include "Box.h"

Box::Box()
{
    this->min = Vector3(-1,-1,-1);
    this->max = Vector3(1,1,1);
}

Box::Box(const Vector3 &min, const Vector3 &max)
{
    this->min = Vector3(MIN(min.x, max.x), MIN(min.y, max.y), MIN(min.z, max.z));
    this->max = Vector3(MAX(min.x, max.x), MAX(min.y, max.y), MAX(min.z, max.z));
}



Box::~Box()
{
}
/*
    tmin     tmax     mint     maxt     x

    tmin     mint     tmax     maxt     tmax

    tmin     mint     maxt     tmax     x

    mint     maxt     tmin     tmax     x
 
    mint     tmin     tmax     maxt     tmin
 
 */



bool Box::intersects(const Ray &ray, real &t, Hit &h) const
{
    real txmin, tymin, tzmin = -INFINITE, txmax, tymax, tzmax=INFINITE;
    real tmin = -INFINITE, tmax=INFINITE;
    
    if(ray.d.x != 0) {
        txmin = (min.x - ray.o.x) / ray.d.x;
        txmax = (max.x - ray.o.x) / ray.d.x;
        
        tmin = MIN(txmin,txmax);
        tmax = MAX(txmin,txmax);
    }
    
    if(ray.d.y != 0) {
        tymin = (min.y - ray.o.y) / ray.d.y;
        tymax = (max.y - ray.o.y) / ray.d.y;
        
        real t0 = MIN(tymin,tymax);
        real t1 = MAX(tymin,tymax);
        
        if(t0 > tmin) tmin = t0;
        if(t1 < tmax) tmax = t1;
    }
    
    if(ray.d.z != 0) {
        tzmin = (min.z - ray.o.z) / ray.d.z;
        tzmax = (max.z - ray.o.z) / ray.d.z;
        
        real t0 = MIN(tzmin,tzmax);
        real t1 = MAX(tzmin,tzmax);
        
        if(t0 > tmin) tmin = t0;
        if(t1 < tmax) tmax = t1;
    }
    
    if(tmin > tmax || tmin > ray.maxt || tmax < ray.mint) return false;
    
    if( tmin > ray.mint)
        t = tmin;
    else if( tmax < ray.maxt)
        t = tmax;
    else return false;
    
    h.p = ray.o + t*ray.d;
    
    if(t == txmin) h.n = Vector3(-1,0,0);
    else if(t == txmax) h.n = Vector3(1,0,0);
    else if(t == tymin) h.n = Vector3(0,-1,0);
    else if(t == tymax) h.n = Vector3(0,1,0);
    else if(t == tzmin) h.n = Vector3(0,0,-1);
    else if(t == tzmax) h.n = Vector3(0,0,1);
    return true;
}


bool Box::intersects(const Ray &ray) const
{
    real txmin, tymin, tzmin = -INFINITE, txmax, tymax, tzmax=INFINITE;
    real tmin = -INFINITE, tmax=INFINITE;
    
    if(ray.d.x != 0) {
        txmin = (min.x - ray.o.x) / ray.d.x;
        txmax = (max.x - ray.o.x) / ray.d.x;
        
        tmin = MIN(txmin,txmax);
        tmax = MAX(txmin,txmax);
    }
    
    if(ray.d.y != 0) {
        tymin = (min.y - ray.o.y) / ray.d.y;
        tymax = (max.y - ray.o.y) / ray.d.y;
        
        real t0 = MIN(tymin,tymax);
        real t1 = MAX(tymin,tymax);
        
        if(t0 > tmin) tmin = t0;
        if(t1 < tmax) tmax = t1;
    }
    
    if(ray.d.z != 0) {
        tzmin = (min.z - ray.o.z) / ray.d.z;
        tzmax = (max.z - ray.o.z) / ray.d.z;
        
        real t0 = MIN(tzmin,tzmax);
        real t1 = MAX(tzmin,tzmax);
        
        if(t0 > tmin) tmin = t0;
        if(t1 < tmax) tmax = t1;
    }
    
    return (tmin <= tmax) && ( inside(tmin, ray.mint, ray.maxt) || inside(tmax, ray.mint, ray.maxt));
}