IDIR = src
ODIR = obj
CC = g++
LIBS = -lm

_DEPS = circle.cpp compare.cpp halfplane.cpp line.cpp main.cpp point.cpp polygon.cpp ray.cpp segment.cpp vector2.cpp
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

hello:
	$(CC) -o $(ODIR)/main.o $(DEPS) $(LIBS)