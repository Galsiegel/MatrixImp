# generic makefile, made by chatGPT

CC = g++
CFLAGS = -std=c++11 -Wall

# List of source files
SRCS = main.cpp complex.cpp

# Object files
OBJS = $(SRCS:.cpp=.o)

# Executable name
EXEC = my_program

# Rule to compile .cpp files to .o files
%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

# Rule to link object files and create the executable
$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(EXEC)

# Clean command
clean:
	rm -f $(OBJS) $(EXEC)
