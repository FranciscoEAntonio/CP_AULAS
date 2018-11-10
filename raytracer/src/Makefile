CXX=c++

CPPFLAGS=-I$(INCLUDEDIR) -g $(CILKPLUS)

SUBDIRS=Core Lights Sensors Shapes

S=main.cpp
O=$(patsubst %.cpp,%.o,$(S))

all: subdirs $(O)

subdirs:
	for dir in $(SUBDIRS); do make -C $$dir INCLUDEDIR=../$(INCLUDEDIR) CILKPLUS=$(CILKPLUS); done

clean:
	for dir in $(SUBDIRS); do make -C $$dir clean; done
	rm -f *.o


# -------------------------------------------------------------------
# Dependencies - do not edit below this point
# -------------------------------------------------------------------
main.o: main.cpp ../include/Scene.h ../include/Instance.h \
  ../include/FullHit.h ../include/Hit.h ../include/Vector3.h \
  ../include/defines.h ../include/TransformSeq.h ../include/Transform.h \
  ../include/Material.h ../include/Color.h ../include/Primitive.h \
  ../include/Ray.h ../include/Light.h Shapes/Box.h Shapes/Plane.h \
  Shapes/Sphere.h Shapes/Cylinder.h ../include/Camera.h \
  ../include/ImageSensor.h ../include/SimpleSensor.h Lights/PointLight.h \
  Lights/SphereLight.h Lights/DirectionalLight.h
