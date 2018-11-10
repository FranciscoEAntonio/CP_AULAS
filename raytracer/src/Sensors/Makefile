CXX=c++

CPPFLAGS=-I$(INCLUDEDIR) -g $(CILKPLUS)

S=SimpleSensor.cpp
O=$(patsubst %.cpp,%.o,$(S))

all: $(O)

clean:
	rm -f *.o


# -------------------------------------------------------------------
# Dependencies - do not edit below this point
# -------------------------------------------------------------------
SimpleSensor.o: SimpleSensor.cpp ../../include/SimpleSensor.h \
  ../../include/ImageSensor.h ../../include/Color.h \
  ../../include/defines.h
