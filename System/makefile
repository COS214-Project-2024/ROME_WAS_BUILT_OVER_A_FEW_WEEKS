CXX = g++
CXXFLAGS = -g -IBoosterStructures -ICheckAdjacentTemplate -ICityStructures \
           -ICityStructures/Road -ICityStructures/Industrial -ICityStructures/Residential \
           -ICityStructures/Commercial -ICityStructures/Landmark -IFactory -IPoliticalSystem \
           -ISatisfactionHandler -I../SFML-2.6.1/include

# SFML library paths and flags
LDFLAGS = -L../SFML-2.6.1/lib -lsfml-graphics -lsfml-window -lsfml-system

# SFML DLL files (adjust the path if they are elsewhere)
SFML_DLLS = ../SFML-2.6.1/bin/sfml-graphics-2.dll ../SFML-2.6.1/bin/sfml-window-2.dll ../SFML-2.6.1/bin/sfml-system-2.dll

# Output directories in the root folder
BUILD_DIR = ../build
BIN_DIR = ../bin

# Source files
SOURCES = $(wildcard *.cpp) $(wildcard BoosterStructures/*.cpp) \
          $(wildcard CheckAdjacentTemplate/*.cpp) $(wildcard CityStructures/*.cpp) \
          $(wildcard CityStructures/Road/*.cpp) $(wildcard CityStructures/Industrial/*.cpp) \
          $(wildcard CityStructures/Residential/*.cpp) $(wildcard CityStructures/Commercial/*.cpp) \
          $(wildcard CityStructures/Landmark/*.cpp) $(wildcard Factory/*.cpp) \
          $(wildcard PoliticalSystem/*.cpp) $(wildcard SatisfactionHandler/*.cpp)

# Object files (placed in the build directory)
OBJECTS = $(patsubst %.cpp,$(BUILD_DIR)/%.o,$(SOURCES))

# Executable name and path
TARGET = $(BIN_DIR)/program

# Build target
$(TARGET): $(OBJECTS) | $(BIN_DIR)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS) $(LDFLAGS)
	# Copy SFML DLLs to the bin directory
	cp $(SFML_DLLS) $(BIN_DIR)

# Rule to compile each .cpp file into an .o file in the build directory
$(BUILD_DIR)/%.o: %.cpp | create_build_dirs
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Create all necessary subdirectories in the build folder
create_build_dirs:
	mkdir -p $(BUILD_DIR)
	mkdir -p $(BUILD_DIR)/BoosterStructures
	mkdir -p $(BUILD_DIR)/CheckAdjacentTemplate
	mkdir -p $(BUILD_DIR)/CityStructures
	mkdir -p $(BUILD_DIR)/CityStructures/Road
	mkdir -p $(BUILD_DIR)/CityStructures/Industrial
	mkdir -p $(BUILD_DIR)/CityStructures/Residential
	mkdir -p $(BUILD_DIR)/CityStructures/Commercial
	mkdir -p $(BUILD_DIR)/CityStructures/Landmark
	mkdir -p $(BUILD_DIR)/Factory
	mkdir -p $(BUILD_DIR)/PoliticalSystem
	mkdir -p $(BUILD_DIR)/SatisfactionHandler

# Ensure bin directory exists
$(BIN_DIR):
	mkdir -p $(BIN_DIR)

# Clean up object files, executable, and copied DLLs
clean:
	rm -rf $(BUILD_DIR) $(BIN_DIR)

# Run the program
run: $(TARGET)
	./$(TARGET)

# Clean up all generated files
clean:
	rm -f $(OBJECTS) $(TARGET)

# Rebuild everything
rebuild: clean $(TARGET)