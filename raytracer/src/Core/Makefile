CXX=c++

CPPFLAGS=-I$(INCLUDEDIR) -g $(CILKPLUS)

S=AreaLight.cpp Camera.cpp Color.cpp defines.cpp FullHit.cpp Hit.cpp ImageSensor.cpp Instance.cpp Light.cpp Material.cpp Primitive.cpp Ray.cpp Scene.cpp Transform.cpp TransformSeq.cpp Vector3.cpp
O=$(patsubst %.cpp,%.o,$(S))

all: $(O)

clean:
	rm -f *.o


# -------------------------------------------------------------------
# Dependencies - do not edit below this point
# -------------------------------------------------------------------
AreaLight.o: AreaLight.cpp ../../include/Light.h ../../include/Color.h \
  ../../include/defines.h ../../include/Vector3.h
Camera.o: Camera.cpp ../../include/Camera.h ../../include/Vector3.h \
  ../../include/defines.h ../../include/Ray.h \
  ../../include/TransformSeq.h ../../include/Transform.h \
  ../../include/Scene.h ../../include/Instance.h ../../include/FullHit.h \
  ../../include/Hit.h ../../include/Material.h ../../include/Color.h \
  ../../include/Primitive.h ../../include/Light.h \
  ../../include/ImageSensor.h
Color.o: Color.cpp ../../include/Color.h ../../include/defines.h
FullHit.o: FullHit.cpp ../../include/FullHit.h ../../include/Hit.h \
  ../../include/Vector3.h ../../include/defines.h \
  ../../include/TransformSeq.h ../../include/Transform.h
Hit.o: Hit.cpp ../../include/Hit.h ../../include/Vector3.h \
  ../../include/defines.h ../../include/TransformSeq.h \
  ../../include/Transform.h
ImageSensor.o: ImageSensor.cpp ../../include/ImageSensor.h \
  ../../include/Color.h ../../include/defines.h
Instance.o: Instance.cpp ../../include/Instance.h ../../include/FullHit.h \
  ../../include/Hit.h ../../include/Vector3.h ../../include/defines.h \
  ../../include/TransformSeq.h ../../include/Transform.h \
  ../../include/Material.h ../../include/Color.h \
  ../../include/Primitive.h ../../include/Ray.h
Light.o: Light.cpp ../../include/Light.h ../../include/Color.h \
  ../../include/defines.h ../../include/Vector3.h
Material.o: Material.cpp ../../include/Material.h ../../include/defines.h \
  ../../include/Color.h
Primitive.o: Primitive.cpp ../../include/Primitive.h ../../include/Hit.h \
  ../../include/Vector3.h ../../include/defines.h \
  ../../include/TransformSeq.h ../../include/Transform.h \
  ../../include/Ray.h ../../include/Color.h
Ray.o: Ray.cpp ../../include/Ray.h ../../include/Vector3.h \
  ../../include/defines.h ../../include/TransformSeq.h \
  ../../include/Transform.h
Scene.o: Scene.cpp ../../include/Scene.h ../../include/Instance.h \
  ../../include/FullHit.h ../../include/Hit.h ../../include/Vector3.h \
  ../../include/defines.h ../../include/TransformSeq.h \
  ../../include/Transform.h ../../include/Material.h \
  ../../include/Color.h ../../include/Primitive.h ../../include/Ray.h \
  ../../include/Light.h
Transform.o: Transform.cpp ../../include/Transform.h \
  ../../include/defines.h ../../include/Vector3.h
TransformSeq.o: TransformSeq.cpp ../../include/TransformSeq.h \
  ../../include/Transform.h ../../include/defines.h \
  ../../include/Vector3.h
Vector3.o: Vector3.cpp ../../include/Vector3.h ../../include/defines.h
defines.o: defines.cpp ../../include/defines.h
DirectionalLight.o: DirectionalLight.cpp DirectionalLight.h \
  ../../include/Light.h ../../include/Color.h ../../include/defines.h \
  ../../include/Vector3.h
PointLight.o: PointLight.cpp PointLight.h ../../include/Light.h \
  ../../include/Color.h ../../include/defines.h ../../include/Vector3.h
SphereLight.o: SphereLight.cpp SphereLight.h PointLight.h \
  ../../include/Light.h ../../include/Color.h ../../include/defines.h \
  ../../include/Vector3.h
