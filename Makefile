
CFLAGS =  --std=c++20
LDFLAGS = -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
COMP = g++

OBJS = raygui.o \
  Main.o

COREHEADERS = Main.o


all: OTENGINE

OTENGINE: $(OBJS)

Main.o: Source/Main.cpp Source/*.hpp 
	$(COMP) $(CFLAGS) -c Source/Main.cpp $(LDFLAGS)


raygui.o: Source/raygui/raygui.c
	$(COMP) $(CFLAGS) -c Source/raygui/raygui.c -shared -DRAYGUI_IMPLEMENTATION -DBUILD_LIBTYPE_SHARED -static-libgcc -lopengl32 -lgdi32 -lwinmm 


OTENGINE:
	$(COMP) $(OBJS) -o OTE $(CFLAGS) $(LDFLAGS)