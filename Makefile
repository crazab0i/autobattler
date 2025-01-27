# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -Werror -std=c++17 -g

# Output binary
TARGET = autobattle.exe

# Source files and object files
SRC = battle.cpp entity.cpp main.cpp mobs.cpp player.cpp simulation.cpp
OBJ = $(SRC:.cpp=.o)

# Default target
all: $(TARGET)

# Link object files to create the binary
$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compile each .cpp file into an object file
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up build files
clean:
	echo "Removing files"
	rm -f $(OBJ) $(TARGET)