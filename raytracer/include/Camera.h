//
//  Camera.h
//  RayTracer
//
//  Created by Fernando Birra on 08/11/13.
//  Copyright (c) 2013 FCT/UNL. All rights reserved.
//

#ifndef __RayTracer__Camera__
#define __RayTracer__Camera__

#include <iostream>

#include "Vector3.h"
#include "Ray.h"
#include "Scene.h"
#include "ImageSensor.h"

class Camera {

public:
    Camera();
    Camera(const Vector3 &eye=Vector3(0,0,1),   // Default eye location (from)
           const Vector3 &at=Vector3(0,0,0),    // Default at location
           const Vector3 &up=Vector3(0,1,0),    // Default up direction
           real fd=0.050,                       // Default focal distance
           real w=0.036,                        // Default film width
           real h=0.024                         // Default film height
    );
    virtual ~Camera();
    
    // Sets the film sensor of the camera
    void setSensor(ImageSensor *s);
    // Main camera function: takes a snapshot of a scene
    void capture(Scene &s, const char *filename="image.tga");
    
private:
    // Used to define the local axis of the camera frame in world space
    void setupAxis();   // sets up the camera coordinate axis

    // Camera data members
public:
    Vector3 eye;        // camera origin
    Vector3 at;         // target
    Vector3 up;         // up vector
    real fd;            // focal distance
    real width;         // real image width
    real height;        // real image height
    
    ImageSensor *sensor;

    Vector3 ez;    // Forward direction
    Vector3 ey;    // Up direction
    Vector3 ex;    // Left direction
};

#endif /* defined(__RayTracer__Camera__) */
