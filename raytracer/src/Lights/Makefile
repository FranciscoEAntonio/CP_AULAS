CXX=c++

CPPFLAGS=-I$(INCLUDEDIR) -g $(CILKPLUS)

S=DirectionalLight.cpp PointLight.cpp SphereLight.cpp
O=$(patsubst %.cpp,%.o,$(S))

all: $(O)

clean:
	rm -f *.o


# -------------------------------------------------------------------
# Dependencies - do not edit below this point
# -------------------------------------------------------------------
DirectionalLight.o: DirectionalLight.cpp DirectionalLight.h \
  ../../include/Light.h ../../include/Color.h ../../include/defines.h \
  ../../include/Vector3.h
PointLight.o: PointLight.cpp PointLight.h ../../include/Light.h \
  ../../include/Color.h ../../include/defines.h ../../include/Vector3.h
SphereLight.o: SphereLight.cpp SphereLight.h PointLight.h \
  ../../include/Light.h ../../include/Color.h ../../include/defines.h \
  ../../include/Vector3.h
