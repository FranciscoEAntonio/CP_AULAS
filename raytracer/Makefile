CXX=c++

INCLUDEDIR=include
CILKPLUS=-fcilkplus

CPPFLAGS=-I$(INCLUDEDIR) -g $(CILKPLUS)


SUBDIRS=src

TARGET=rt

S=./src/Sensors/SimpleSensor.cpp ./src/Core/TransformSeq.cpp ./src/Core/FullHit.cpp ./src/Core/Scene.cpp ./src/Core/Vector3.cpp ./src/Core/Camera.cpp ./src/Core/Hit.cpp ./src/Core/Light.cpp ./src/Core/Ray.cpp ./src/Core/ImageSensor.cpp ./src/Core/Color.cpp ./src/Core/Transform.cpp ./src/Core/AreaLight.cpp ./src/Core/Primitive.cpp ./src/Core/defines.cpp ./src/Core/Instance.cpp ./src/Core/Material.cpp ./src/Shapes/Cylinder.cpp ./src/Shapes/Box.cpp ./src/Shapes/Sphere.cpp ./src/Shapes/Plane.cpp ./src/Lights/DirectionalLight.cpp ./src/Lights/PointLight.cpp ./src/Lights/SphereLight.cpp ./src/main.cpp

O=$(patsubst %.cpp,%.o,$(S))

all: $(TARGET)

$(TARGET): subdirs
	$(CXX) $(CPPFLAGS) -o $(TARGET) $(O)

subdirs:
	for dir in $(SUBDIRS); do make -C $$dir INCLUDEDIR=../$(INCLUDEDIR) CILKPLUS=$(CILKPLUS); done

clean:
	for dir in $(SUBDIRS); do make -C $$dir clean; done
	rm -f *.o $(TARGET)


# -------------------------------------------------------------------
# Dependencies - do not edit below this point
# -------------------------------------------------------------------
