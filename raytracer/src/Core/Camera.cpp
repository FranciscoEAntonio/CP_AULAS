//
//  Camera.cpp
//  RayTracer
//
//  Created by Fernando Birra on 08/11/13.
//  Copyright (c) 2013 FCT/UNL. All rights reserved.
//

#include <ctime>

#include "Camera.h"
#include <cilk/cilk.h>

Camera::Camera(): eye(), at(0,0,-1), up(0,1,0), fd(0.050), width(0.036), height(0.024), sensor(NULL)
{
    setupAxis();
}

Camera::Camera(const Vector3 &eye, const Vector3 &at, const Vector3 &up, real fd, real width, real height):
    eye(eye), at(at), up(up), fd(fd), width(width), height(height), sensor(NULL)
{
    setupAxis();
}

Camera::~Camera()
{
}

void Camera::setSensor(ImageSensor *s)
{
    // Discard previous sensor if it exists
    if(sensor) delete sensor;
    
    // replace with new one
    sensor = s;
}

void Camera::capture(Scene &s, const char *filename)
{
    // No sensor no capture
    if(!sensor) return;
    
    clock_t start=clock();
    
    // Inform the scene of the location of the camera
    s.setCameraPos(eye);
    
    // compute the center of the virtual sensor, placed at the focal distance
    // along the direction from the eye to the at point (negative camera's forward direction)
    Vector3 center = eye - ez * fd;
    
    // Compute the top left corner of the sensor, in WC
    Vector3 topleft = center - ex * .5 * width + ey * .5 * height;
    
    // How to go from one pixel to the one at its right
    Vector3 dx = ex * (width / sensor->w); // Horizontal distance between pixels in image sensor
    // How to go from one pixel to the one immediatelly below it
    Vector3 dy = -ey * (height / sensor->h); // Vertical distance between pixels in image sensor
    
    // Compute the center of the top left pixel
    Vector3 pixel = topleft + dx * 0.5 - dy * .5;   // Center of the pixel
    Vector3 initial = pixel;
    Vector3 left = pixel;
    cilk_for(unsigned int j=0; j<sensor->h; j++)
    {
        cilk_for(unsigned int i=0; i<sensor->w; i++)
        {
			pixel = initial + i*dx + j*dy;

            // Compute vector from eye to the center of the current pixel
            Vector3 to = pixel - eye;
            // and normalize it
            to.normalize();
            
            // Create a ray starting at the eye and passing through the center of the pixel
            Ray r(eye, to);
            
            // Compute the color of the ray (Ray tracing algorithm)
            Color c = s.traceRay(r);
            
            // Add this sample to the sensor
            sensor->addSample(i,j,c);
            
            // Move to the pixel on the right
            //pixel += dx;
        }
        // Move to the pixel below the leftmost pixel of the current line
        //left += dy;

        //pixel = left;
    }
    
    // "process" the image
    this->sensor->process();
    
    clock_t end = clock();
    double time = (double) (end-start) / CLOCKS_PER_SEC * 1000.0;
    
    std::cout << "Rendering time for " << filename << ": " << time << std::endl;
    // Dump the image to a file
    this->sensor->dumpToTGA(filename);
}

void Camera::setupAxis()
{
    // ez is a unit vector pointing from at to eye
    ez = eye - at;
    ez.normalize();
    
    // ex is orthogonal to the plane formed by up and (at-eye)
    ex = up.cross(ez);
    ex.normalize();
    
    // finally ey is also orthogonal to the plane formed by ey and ez
    ey = ez.cross(ex);
    ey.normalize();    // This shouldn't be necessary
}

