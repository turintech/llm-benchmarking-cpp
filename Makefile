# Parallel Settings
PARALLEL ?= 1

# Compiler Settings
CXX = g++
CXXFLAGS = -std=c++2a -O3 -Wall

# Paths
SRC = src
BUILD = build

# Project Files
SOURCES = $(wildcard $(SRC)/control/*.cc $(SRC)/strings/*.cc $(SRC)/algorithms/*.cc $(SRC)/datastructures/*.cc $(SRC)/math/*.cc) $(SRC)/main.cc
OBJECTS = $(SOURCES:$(SRC)/%.cc=$(BUILD)/%.o)
EXECUTABLE = $(BUILD)/main

# Default (CMake)
all: 
	cmake -S . -B $(BUILD)

# No CMake
nocmake: 
	$(BUILD) $(EXECUTABLE)

compile:
	cmake --build $(BUILD) -- -j$(PARALLEL)

# Create Build
$(BUILD):
	mkdir -p $(BUILD)

# Linking
$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $@

# Compiling
$(BUILD)/%.o: $(SRC)/%.cc
	mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Cleaning
clean:
	rm -rf $(BUILD)

# Phony
.PHONY: all clean
