# # Compiler
# CXX = g++
# # Compiler flags
# CXXFLAGS = -g -Wall -IBoosterStructures -ICheckAdjacent -ICityStructures -ICityStructures/Industrial -ICityStructures/Commercial -ICityStructures/Residential -ICityStructures/Landmark -ICityStructures/Road -IFactory -IPoliticalSystem -ISatisfactionHandler
# # Executable name
# TARGET = program 

# # Source files
# SOURCES = \
#     Airport.cpp \
#     Apartment.cpp \
#     Authoritarianism.cpp \
#     BoosterStructures.cpp \
#     CityHall.cpp \
#     CityMap.cpp \
#     CityStructure.cpp \
#     Colosseum.cpp \
#     CommercialBuilding.cpp \
#     Communsim.cpp \
#     Concrete.cpp \
#     ConcreteGenerator.cpp \
#     Democracy.cpp \
#     Estate.cpp \
#     Factory.cpp \
#     HighSatisfactionHandler.cpp \
#     HighTraffic.cpp \
#     House.cpp \
#     IndustrialBuilding.cpp \
#     Landmark.cpp \
#     LowSatisfactionHandler.cpp \
#     LowTraffic.cpp \
#     main.cpp \
#     Mall.cpp \
#     MediumSatisfactionHandler.cpp \
#     MediumTraffic.cpp \
#     Office.cpp \
#     Pantheon.cpp \
#     Park.cpp \
#     PoliticalSystem.cpp \
#     PowerPlant.cpp \
#     Railway.cpp \
#     ResidentialBuilding.cpp \
#     ResidentialComplex.cpp \
#     Road.cpp \
#     SatisfactionHandler.cpp \
#     SewagePlant.cpp \
#     Shop.cpp \
#     Steel.cpp \
#     SteelGenerator.cpp \
#     Townhouse.cpp \
#     Warehouse.cpp \
#     WastePlant.cpp \
#     WaterPlant.cpp \
#     Wood.cpp \
#     WoodGenerator.cpp \
# 	CheckAdjacent.cpp \

# # Object files
# OBJECTS = $(SOURCES:.cpp=.o)

# # Default rule to build the executable
# $(TARGET): $(OBJECTS)
# 	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)

# # Rule to compile .cpp files to .o files
# %.o: %.cpp
# 	$(CXX) $(CXXFLAGS) -c $< -o $@

# # Run the program
# run: $(TARGET)
# 	./$(TARGET)

# # Clean up all generated files
# clean:
# 	rm -f $(OBJECTS) $(TARGET)

# # Rebuild everything
# rebuild: clean $(TARGET)


# Compiler
CXX = g++
CXXFLAGS = -g -IBoosterStructures -ICheckAdjacentTemplate -ICityStructures \
           -ICityStructures/Road -ICityStructures/Industrial -ICityStructures/Residential \
           -ICityStructures/Commercial -ICityStructures/Landmark -IFactory -IPoliticalSystem \
           -ISatisfactionHandler

# Output directories in the root folder
BUILD_DIR = ../build
BIN_DIR = ../bin

# Detect platform
ifeq ($(shell uname), Darwin)
    # macOS configuration with .dylib files
    CXXFLAGS += -I../SFML-2.6.1/macOS/include
    LDFLAGS = -L../SFML-2.6.1/macOS/lib -lsfml-graphics -lsfml-window -lsfml-system
else
    # Windows configuration with .dll files
    CXXFLAGS += -I../SFML-2.6.1/Windows/include
    LDFLAGS = -L../SFML-2.6.1/Windows/lib -lsfml-graphics -lsfml-window -lsfml-system
    SFML_DLLS = ../SFML-2.6.1/Windows/bin/sfml-graphics-2.dll ../SFML-2.6.1/Windows/bin/sfml-window-2.dll ../SFML-2.6.1/Windows/bin/sfml-system-2.dll
endif

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

	# Copy SFML DLLs to the bin directory for Windows only
ifneq ($(shell uname), Darwin)
	cp $(SFML_DLLS) $(BIN_DIR)
endif

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

