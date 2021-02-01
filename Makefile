#OBJS specifies which files to compile as part of the project
OBJS = TicTacToe.cpp

#CC specifies which compiler we're using
CC = g++

#COMPILER_FLAGS specifies the additional compilation options we're using
#-w supperesses all warnings
COMPILER_FLAGS = -w

#LINKER_FLAGS specifies the librairies we're linking against
LINKER_FLAGS = 

#OBJ_NAME specifies the name of our exectuable
OBJ_NAME = TicTacToe

#This is the target that compiles our executable
all : $(OBJS)
	$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)