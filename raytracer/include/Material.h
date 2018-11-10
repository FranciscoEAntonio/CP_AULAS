//
//  Material.h
//  RayTracer
//
//  Created by Fernando Birra on 24/12/13.
//  Copyright (c) 2013 FCT/UNL. All rights reserved.
//

#ifndef __RayTracer__Material__
#define __RayTracer__Material__

#include <iostream>

#include "defines.h"

#include "Color.h"

class Material {

public:
    Material() : ka(), kd(), ks(1.0, 1.0, 1.0), kr(0.0, 0.0, 0.0), kt(0.0, 0.0, 0.0), ns(0.0), nt(1.0)
    {
        isTransmissive = kt != Color::black;
        isReflective = kr != Color::black;
    };
    Material(const Color &ka,                               // Ambient color
             const Color &kd,                               // Diffuse color
             const Color &ks = Color(0.0, 0.0, 0.0),        // Specular color
             const Color &kr = Color(0.0, 0.0, 0.0),        // Color for reflection rays
             const Color &kt=Color(0.0, 0.0, 0.0),          // Color for transmitted rays
             int ns=1,                                      // shininess
             real nt=1                                      // refraction index
    ): ka(ka), kd(kd), ks(ks), kr(kr), kt(kt), ns(ns), nt(nt)
    {
        isTransmissive = kt != Color::black;
        isReflective = kr != Color::black;
    };
    virtual ~Material() {};
    
public:
    Color ka, kd, ks, kr, kt;
    int ns;
    real nt;
    bool isTransmissive;
    bool isReflective;
};
#endif /* defined(__RayTracer__Material__) */
