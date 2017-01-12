#OBJS specifies which files to compile as part of the project
OBJS = main.cpp

#OBJ_NAME specifies the name of our exectuable
OBJ_NAME = SDLMain

#This is the target that compiles our executable
all : $(OBJS)
	g++ $(OBJS) -IC:\Development\SDL2_MinGW_32Bit\include -LC:\Development\SDL2_MinGW_32Bit\lib -w -Wl,-subsystem,windows -lmingw32 -lSDL2main -lSDL2 -o $(OBJ_NAME)
