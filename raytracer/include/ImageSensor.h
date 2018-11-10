//
//  ImageSensor.h
//  RayTracer
//
//  Created by Fernando Birra on 24/12/13.
//  Copyright (c) 2013 FCT/UNL. All rights reserved.
//

#ifndef __RayTracer__ImageSensor__
#define __RayTracer__ImageSensor__

#include <iostream>

#include "Color.h"

class ImageSensor {
public:
    static const int DEFAULT_RES_X = 320;
    static const int DEFAULT_RES_Y = 240;

    ImageSensor();
    ImageSensor(int width, int height);
    virtual ~ImageSensor();
    
    // Adds a sample with color c to the pixel at (i,j)
    virtual void addSample(unsigned int i, unsigned int j, Color c);
    
    // Dumps the contents of the image sensor into a TGA file
    virtual void dumpToTGA(const char *filename) const;
    
    // Used to "reveal" the picture
    virtual void process() = 0;
    
private:
    void allocateStorage();
    void deallocateStorage();
    unsigned int indexFor(unsigned int i, unsigned int j) const;
    
public:
    // Data members
    int w, h; // Image resolution
    Color *data;
    int *nsamples;
};
#endif /* defined(__RayTracer__ImageSensor__) */

