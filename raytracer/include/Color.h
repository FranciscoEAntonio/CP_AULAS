//
//  RGB.h
//  RayTracer
//
//  Created by Fernando Birra on 07/11/13.
//  Copyright (c) 2013 FCT/UNL. All rights reserved.
//

#ifndef __RayTracer__RGB__
#define __RayTracer__RGB__

#include <iostream>

#include "defines.h"

class Color {

public:
    
    static Color black;
    static Color white;
    
    // black constructor
    Color();
    // Color from components
    Color(real r,real g,real b);
    // Destructor
    virtual ~Color();
    
    // data storage
    real r, g, b;
};

// Add two colors
Color operator +(const Color &c1, const Color &c2);
// Subtract two colors
Color operator -(const Color &c1, const Color &c2);
// Component wise multiplication (Color modulation)
Color operator *(const Color &c1, const Color &c2);

// c1 = c1 + c2
Color& operator +=(Color &c1, const Color &c2);
// c1 = c1 - c2
Color& operator -=(Color &c1, const Color &c2);
// c1 = c1 * c2
Color& operator *=(Color &c1, const Color &c2);

// scale a color by ammount f
Color operator *(const Color &c, real f);

// scale a color by ammount f
Color operator /(const Color &c, real f);

// c = c * f (color scale)
Color& operator *=(Color &c, real f);

// c = c / f (color scale)
Color& operator /=(Color &c, real f);

// check if two colors are the same
bool operator ==(const Color &c1, const Color &c2);
// check if two colors are different
bool operator !=(const Color &c1, const Color &c2);

// returns a * s + b * (1-s)
Color mix(const Color &a, const Color &b, real s);

// outputs a color to an output stream
std::ostream& operator << (std::ostream &os, const Color &c);

#endif /* defined(__RayTracer__RGB__) */
