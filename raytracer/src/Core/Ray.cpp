//
//  Ray.cpp
//  RayTracer
//
//  Created by Fernando Birra on 07/11/13.
//  Copyright (c) 2013 FCT/UNL. All rights reserved.
//

#include "Ray.h"
#include "TransformSeq.h"

Ray::Ray(const Vector3 &o, const Vector3 &d, real mint, real maxt): o(o), d(d), mint(mint), maxt(maxt)
{
}

Ray::~Ray()
{
}

Ray Ray::worldToLocal(const TransformSeq &ts) const
{
    // Use inverse transformation to go from world to local
    //    Vector3 ori = ts.tinv.applyToPoint(this->o);
    //    Vector3 dir = ts.tinv.applyToVector(this->d);
    Vector3 ori = ts.applyInverseToPoint(this->o);
    Vector3 dir = ts.applyInverseToVector(this->d);
	
    return Ray(ori, dir, mint, maxt);
}

Ray Ray::reflected(const Vector3 &p, const Vector3 &n) const
{
    // Return a reflected version of the ray by normal n and starting at point p
    Ray r(p, this->d.reflected(n));
    return r;
}

Ray Ray::refracted(const Vector3 &p, const Vector3 &n, real nr) const
{
    return Ray(p, this->d.refracted(n, nr));
}

Vector3 Ray::position(real t) const
{
    return o + t*d;
}

std::ostream& operator << (std::ostream &os, const Ray &r)
{
    os << "(o=" << r.o << " d=" << r.d << ")" << std::endl;
    return os;
}
