AutomatedMakefile = am
CC = g++

INC_DIRS = -I$(PROJECT_PATH)/ -I$(PROJECT_PATH)/CSC1310/include
LIB_DIRS = -L$(PROJECT_PATH)/ -L$(PROJECT_PATH)/CSC1310/ 
LIBS = -lCSC1310

COMPILE = $(CC) $(INC_DIRS) -c
LINK = $(CC) $(LIB_DIRS) -o

FILES = Edge.o GraphDriver.o
all: Graphs

GraphTraversal: 		$(FILES)
				$(LINK) Graphs.exe $(FILES) $(LIBS)

Edge.o:			Edge.h Edge.cpp
			$(COMPILE) Edge.cpp

GraphDriver.o:		Graph.h GraphDriver.cpp
			$(COMPILE) GraphDriver.cpp
