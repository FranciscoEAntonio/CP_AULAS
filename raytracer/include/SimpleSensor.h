//
//  SimpleImageSensor.hpp
//  RayTracer
//
//  Created by Fernando Pedro Birra on 03/05/16.
//  Copyright © 2016 FCT/UNL. All rights reserved.
//

#ifndef SimpleSensor_hpp
#define SimpleSensor_hpp

#include <stdio.h>

#include "ImageSensor.h"

class SimpleSensor : public ImageSensor {
public:
    SimpleSensor();
    SimpleSensor(int width, int height);
    virtual ~SimpleSensor();
    
    virtual void process();
};

#endif /* SimpleSensor_hpp */
