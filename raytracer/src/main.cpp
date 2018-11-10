#include <iostream>

#include "Scene.h"
#include "Shapes/Box.h"
#include "Shapes/Plane.h"
#include "Shapes/Sphere.h"
#include "Shapes/Cylinder.h"
#include "Camera.h"
#include "SimpleSensor.h"
#include "Lights/PointLight.h"
#include "Lights/SphereLight.h"
#include "Lights/DirectionalLight.h"

Material green1(Color(0.0, 0.2, 0.0), Color(0.0, 0.4, 0.0), Color(1,1,1), Color(0.2,0.2,0.2)*0, Color::black, 50, 1);
Material refractive(Color(0.0, 0.0, 0.0), Color(0.0, 0.0, 0.0), Color(1, 1, 1), Color(0.25, 0.25, 0.25), Color::white*0.8, 50, 1.5);
Material red(Color(0.0, 0.0, 0.0), Color(0.4, 0.0, 0.0), Color(0.4,0.4,0.4), Color(0.7, 0.5, 0.5), Color::black, 50, 1);
Material reflectivegreen(Color(0.0, 0.2, 0.0), Color(0.0, 0.2, 0.0), Color(1,1,1)*0.3, Color(0.2,0.2,0.2), Color::black, 50, 1);
Material red2(Color(0.1, 0.1, 0.1), Color(0.4, 0.3, 0.3), Color(0.4,0.3,0.3), Color(0.7, 0.5, 0.5)*0.3, Color(0.7, 0.5, 0.5), 500, 1.5);
Material green2(Color(0.0, 0.3, 0.0), Color(0.0, 0.6, 0.0), Color(1,1,1), Color(0.2, 0.2, 0.2), Color::black, 500, 1);

void glassBoxScene()
{
    Scene s;
    
    TransformSeq ts1; ts1.addTranslation(0, 0, -4);
    TransformSeq ts2; ts2.addTranslation(-1, 0, 4);
    
    s.addInstance(new Instance(new Sphere(), ts1, red));
    s.addInstance(new Instance(new Box(), TransformSeq(), refractive));
    s.addInstance(new Instance(new Box(), ts2, green1));
    
    
    s.addLight(new DirectionalLight(Color(0.3, 0.3, 0.3), Vector3(0.0,1.0, 0.0)));
    s.addLight(new PointLight(Color::white, Vector3(8,10,2)));

    s.setBackground(Color(0.3, 0.7, 0.8));
    
    Camera cam(Vector3(1.7,1.1,5)*1.5);
    ImageSensor *is = new SimpleSensor(900,600);
    cam.setSensor(is);
    cam.capture(s, "glassbox.tga");
}

void insideBoxScene()
{
    Scene s;
    
    TransformSeq ts;
    
    s.addInstance(new Instance(new Box(Vector3(-10,-10,-10), Vector3(10,10,10)), ts, reflectivegreen));
    
    s.addLight(new PointLight(Color::white, Vector3(8,7,2)));
    
    s.setBackground(Color(0.3, 0.7, 0.8));
    
    Camera cam(Vector3(2,3,4), Vector3(10,10,10));
    ImageSensor *is = new SimpleSensor(900,600);
    cam.setSensor(is);
    cam.capture(s, "inside.tga");
}

void refractiveSphere()

{
    Scene s;
    
    
    TransformSeq ts1;  ts1.addTranslation(0, -1, 0);
    TransformSeq ts3;
    
    s.addInstance(new Instance(new Sphere(), ts3, refractive));
    s.addInstance(new Instance(new Plane(), ts1, green1));
    
    s.addLight(new DirectionalLight(Color(0.3, 0.3, 0.3), Vector3(0.0,1.0, 0.0)));
    s.addLight(new PointLight(Color::white, Vector3(0,10,0)));
    //s.addLight(new SphereLight(Color::white, Vector3(0,10,0)));
    
    s.setBackground(Color(0.3, 0.7, 0.8));

    Camera cam(Vector3(0,2.1,5));
    ImageSensor *is = new SimpleSensor(900,600);
    cam.setSensor(is);
    cam.capture(s, "refractive_sphere.tga");
}

void singleSphereScene()
{
    Scene s;
    
    TransformSeq ts1; ts1.addScale(1.2,1.2,0.7).addTranslation(0, 0, -1.2);
    
    s.addInstance(new Instance(new Sphere(), ts1, green2));
    
    s.addLight(new PointLight(Color::white*0.6, Vector3(0,10,10)));
    
    Camera cam(Vector3(0,0,10));
    ImageSensor *is = new SimpleSensor(900,600);
    
    cam.setSensor(is);
    cam.capture(s, "single_sphere.tga");
}

void threeSpheresScene()
{
    Scene s;
    
    Material red(Color(0.0, 0.0, 0.0), Color(0.4, 0.0, 0.0), Color(0.4,0.4,0.4), Color(0.7, 0.5, 0.5), Color::black, 50, 1);
    Material blue(Color(0.0, 0.0, 0.0), Color(0.0, 0.0, 0.0), Color(0.4, 0.4, 0.4), Color(0.5, 0.5, 0.7), Color::black, 50, 1);
    Material green(Color(0.0, 0.1, 0.0), Color(0.0, 0.6, 0.0));
    
    TransformSeq ts0; ts0.addScale(1.5, 1.5, 1.5).addTranslation(0, 0, 0);
    TransformSeq ts1; ts1.addScale(0.5, 1.0, 1.0).addTranslation(0, 0, 1);
    TransformSeq ts2; ts2.addScale(0.5, 0.5, 0.5).addTranslation(-1.0, 1.6, 1.0);
    TransformSeq ts3; ts3.addScale(0.5, 0.5, 0.5).addTranslation(1.0, 1.6, 1.0);
    
    s.addInstance(new Instance(new Sphere(), ts0, red));
    s.addInstance(new Instance(new Sphere(), ts1, green));
    s.addInstance(new Instance(new Sphere(), ts2, blue));
    s.addInstance(new Instance(new Sphere(), ts3, blue));
    
    s.addLight(new PointLight(Color::white, Vector3(0,10,10)));
    s.addLight(new DirectionalLight(Vector3(0.0,-1.0, 0.0)));

    s.setBackground(Color(0.3, 0.7, 0.8));
    
    Camera cam(Vector3(0,0,10));
    ImageSensor *is = new SimpleSensor(900,600);
    
    cam.setSensor(is);
    cam.capture(s, "threespheres.tga");
}

void threeSpheresAndPlaneScene()
{
    Scene s;
    
    Material red(Color(0.0, 0.0, 0.0), Color(0.4, 0.0, 0.0), Color(0.4,0.4,0.4), Color(0.7, 0.5, 0.5), Color::black, 50, 1);
    Material yellow(Color(0.1, 0.1, 0.0), Color(0.3, 0.3, 0.0));
    Material blue(Color(0.0, 0.0, 0.0), Color(0.0, 0.0, 0.0), Color(0.4, 0.4, 0.4), Color(0.5, 0.5, 0.7), Color::black, 50, 1);
    Material green(Color(0.0, 0.1, 0.0), Color(0.0, 0.6, 0.0));
    Material refractive(Color(0.0, 0.0, 0.0), Color(0.0, 0.0, 0.0), Color(1, 1, 1), Color(0.25, 0.25, 0.25), Color::white*0.8, 50, 1.5);
    
    TransformSeq ts0; ts0.addScale(1.5, 1.5, 1.5).addTranslation(0, 0, 0);
    TransformSeq ts1; ts1.addScale(0.5, 1.0, 1.0).addTranslation(0, 0, 1);
    TransformSeq ts2; ts2.addScale(0.5, 0.5, 0.5).addTranslation(-1.0, 1.6, 1.0);
    TransformSeq ts3; ts3.addScale(0.5, 0.5, 0.5).addTranslation(1.0, 1.6, 1.0);
    TransformSeq ts4; ts4.addTranslation(0,0.5,0).addScale(0.3, 1, 0.3).addTranslation(0, 1.5, 0);
    TransformSeq ts5; ts5.addTranslation(0,1,0).addScale(0.3, 0.3, 0.3).addTranslation(-1,-2,2);
    
    s.addInstance(new Instance(new Sphere(), ts0, red));
    s.addInstance(new Instance(new Sphere(), ts1, green));
    s.addInstance(new Instance(new Sphere(), ts2, blue));
    s.addInstance(new Instance(new Sphere(), ts3, blue));
    s.addInstance(new Instance(new Cylinder(), ts4, green));
    s.addInstance(new Instance(new Plane(Vector3(0,1,0), 2), TransformSeq(), yellow));
    s.addInstance(new Instance(new Box(), ts5, green));
    s.addInstance(new Instance(new Box(), ts5.addTranslation(2, 0.001, 0), refractive));
    
    s.addLight(new PointLight(Color::white, Vector3(-10,10,4)));
    s.addLight(new DirectionalLight(Vector3(-1.0,-1.0, -1.0)));
    
    s.setBackground(Color(0.3, 0.7, 0.8));
    
    Camera cam(Vector3(0,3*1.5,10*1.5));
    
    s.maxDepth = 10;
    cam.setSensor(new SimpleSensor(900, 600));
    cam.capture(s, "plane.tga");
}

void threeSpheresAndPlaneScene2()
{
    Scene s;
    
    Material red(Color(0.0, 0.0, 0.0), Color(0.4, 0.0, 0.0), Color(0.4,0.4,0.4), Color(0.7, 0.5, 0.5), Color::black, 50, 1);
    Material yellow(Color(0.1, 0.1, 0.0), Color(0.3, 0.3, 0.0));
    Material blue(Color(0.0, 0.0, 0.0), Color(0.0, 0.0, 0.0), Color(0.4, 0.4, 0.4), Color(0.5, 0.5, 0.7), Color::black, 50, 1);
    Material green(Color(0.0, 0.1, 0.0), Color(0.0, 0.6, 0.0));
    
    TransformSeq ts0; ts0.addScale(1.5, 1.5, 1.5).addTranslation(0, 0, 0);
    TransformSeq ts1; ts1.addScale(0.5, 1.0, 1.0).addTranslation(0, 0, 1);
    TransformSeq ts2; ts2.addScale(0.5, 0.5, 0.5).addTranslation(-1.0, 1.6, 1.0);
    TransformSeq ts3; ts3.addScale(0.5, 0.5, 0.5).addTranslation(1.0, 1.6, 1.0);
    TransformSeq ts4; ts4.addTranslation(0,0.5,0).addScale(0.3, 1, 0.3).addTranslation(0, 1.5, 0);
    TransformSeq ts5; ts5.addTranslation(0,1,0).addScale(0.3, 0.3, 0.3).addTranslation(-1,-2,2);
    
    s.addInstance(new Instance(new Sphere(), ts0, red));
    s.addInstance(new Instance(new Sphere(), ts1, green));
    s.addInstance(new Instance(new Sphere(), ts2, blue));
    s.addInstance(new Instance(new Sphere(), ts3, blue));
    s.addInstance(new Instance(new Cylinder(), ts4, green));
    s.addInstance(new Instance(new Plane(Vector3(0,1,0), 2), TransformSeq(), yellow));
    s.addInstance(new Instance(new Box(), ts5, green));
    
    s.addLight(new SphereLight(Color::white, Vector3(-10,10,4)));
    s.addLight(new DirectionalLight(Vector3(-1.0,-1.0, -1.0)));
    
    s.setBackground(Color(0.3, 0.7, 0.8));
    
    Camera cam(Vector3(0,3*1.5,10*1.5));
    
    s.maxDepth = 10;
    cam.setSensor(new SimpleSensor(900, 600));
    cam.capture(s, "plane-soft.tga");
}

void testCylinder()
{
    Scene s;
    
    Material red(Color(0.0, 0.0, 0.0), Color(0.4, 0.0, 0.0));
    Material yellow(Color(0.2, 0.2, 0.0), Color(0.5, 0.5, 0.0));
    Material green(Color(0.0, 0.1, 0.0), Color(0.0, 0.6, 0.0));
    
    TransformSeq ts1 = TransformSeq(); ts1.addTranslation(3, 0, 0);
    
    s.addInstance(new Instance(new Cylinder(), TransformSeq(), green));
    //s.addInstance(new Instance(new Sphere(), ts1, red));
    //s.addInstance(new Instance(new Plane(Vector3(0,1,0), 2), TransformSeq(), yellow));
    
    //s.addLight(new PointLight(Vector3(0,10,10)));
    s.addLight(new DirectionalLight(Vector3(0,-0.2,-1)));
    
    s.setBackground(Color(0.3, 0.7, 0.8));
    
    Camera cam(Vector3(0,3,10));
    ImageSensor *is = new SimpleSensor(900,600);
    
    s.maxDepth = 20;
    cam.setSensor(is);
    cam.capture(s, "cylinder.tga");
    
}

void testAreaLight()
{
    Scene s;
    
    Material red(Color(0.1, 0.1, 0.1), Color(0.4, 0.4, 0.4));
    Material yellow(Color(0.2, 0.2, 0.0), Color(0.5, 0.5, 0.0));
    
    s.addInstance(new Instance(new Sphere(), TransformSeq(), red));
    s.addInstance(new Instance(new Plane(Vector3(0,1,0), 2), TransformSeq(), yellow));
    
//    s.addLight(new PointLight(Color::white, Vector3(0,10,0)));
    s.addLight(new SphereLight(Color(1.0, 1.0, 1.0), Vector3(0,10,0), 1));

    s.setBackground(Color(0.3, 0.7, 0.8));
    
    Camera cam(Vector3(0,4.5,15)*0.4);
    ImageSensor *is = new SimpleSensor(900,600);
    
    s.maxDepth = 20;
    cam.setSensor(is);
    cam.capture(s, "arealight.tga");
}

void testRefraction() {
    Scene s;
    
    Material green(Color(0.0, 0.4, 0.0), Color(0.0, 0.8, 0.0), Color(1, 1, 1), Color(0.2, 0.2, 0.2)*0, Color::black, 50, 1.00001);
    Material refractive(Color(0.0, 0.0, 0.0), Color(0.0, 0.0, 0.0), Color(1, 1, 1), Color(0.1, 0.1, 0.1), Color::white, 5, 1.33);
    
    TransformSeq ts1, ts2;
    ts2.addRoty(10); ts2.addRotx(20); ts2.addTranslation(1, 0, -3);
    
    s.addInstance(new Instance(new Sphere(), ts1, refractive));
    s.addInstance(new Instance(new Box(Vector3(-1, -1, -1), Vector3(1, 1, 1)), ts2, green));
    
    s.addLight(new PointLight(Color::white, Vector3(0, 5, 5)));
    s.setBackground(Color(0.3, 0.7, 0.8));
    Camera cam(Vector3(0, 0, 10));
    ImageSensor *is = new SimpleSensor(900, 600);
    
    cam.setSensor(is);
    cam.capture(s, "refraction.tga");
}


void testRefraction2() {
    Scene s;
    
    Material green(Color(0.0, 0.4, 0.0), Color(0.0, 0.8, 0.0), Color(1, 1, 1), Color(0.2, 0.2, 0.2), Color::black, 200, 1.00001);
    Material refractive(Color(0.0, 0.0, 0.0), Color(0.0, 0.0, 0.0), Color(1, 1, 1), Color(0.1, 0.1, 0.1), Color::white, 5, 1.33);
    
    TransformSeq ts1, ts2;
    
    s.addInstance(new Instance(new Sphere(), ts1, refractive));
    s.addInstance(new Instance(new Plane(Vector3(0, 1, 0), Vector3(0, -1, 0)), ts2, green));
    
    s.addLight(new PointLight(Color::white, Vector3(0, 5, 5)));
    s.setBackground(Color(0.3, 0.7, 0.8));
    Camera cam(Vector3(0, 0, 10));
    ImageSensor *is = new SimpleSensor(900, 600);
    
    cam.setSensor(is);
    cam.capture(s, "refraction2.tga");
    
}

void tests()
{
    for(int i=0; i<10; i++) {
        Vector3 a = Vector3::randomDir();
        Vector3 n = Vector3::randomDir();
        
        Vector3 b = a.reflected(n);
        
        std::cout << a.length() << " " << a;
        std::cout << n.length() << " " << n;
        std::cout << b.length() << " " << b;
        std::cout << a.dot(n) << "==" << b.dot(n) << "?" << std::endl;
    }
}

int main(int argc, char *argv[])
{

    glassBoxScene();
    insideBoxScene();
    refractiveSphere();
    singleSphereScene();

    threeSpheresScene();

    threeSpheresAndPlaneScene();
    threeSpheresAndPlaneScene2();
    testCylinder();
    testAreaLight();
    testRefraction();
    testRefraction2();

    return 0;
}




