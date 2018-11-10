CXX=c++

CPPFLAGS=-I$(INCLUDEDIR) -g $(CILKPLUS)

S=Box.cpp Cylinder.cpp Plane.cpp Sphere.cpp
O=$(patsubst %.cpp,%.o,$(S))

all: $(O)

clean:
	rm -f *.o


# -------------------------------------------------------------------
# Dependencies - do not edit below this point
# -------------------------------------------------------------------
Box.o: Box.cpp Box.h ../../include/Primitive.h ../../include/Hit.h \
  ../../include/Vector3.h ../../include/defines.h \
  ../../include/TransformSeq.h ../../include/Transform.h \
  ../../include/Ray.h ../../include/Color.h
Cylinder.o: Cylinder.cpp Cylinder.h ../../include/Primitive.h \
  ../../include/Hit.h ../../include/Vector3.h ../../include/defines.h \
  ../../include/TransformSeq.h ../../include/Transform.h \
  ../../include/Ray.h ../../include/Color.h
Plane.o: Plane.cpp Plane.h ../../include/Primitive.h ../../include/Hit.h \
  ../../include/Vector3.h ../../include/defines.h \
  ../../include/TransformSeq.h ../../include/Transform.h \
  ../../include/Ray.h ../../include/Color.h
Sphere.o: Sphere.cpp Sphere.h ../../include/Primitive.h \
  ../../include/Hit.h ../../include/Vector3.h ../../include/defines.h \
  ../../include/TransformSeq.h ../../include/Transform.h \
  ../../include/Ray.h ../../include/Color.h
