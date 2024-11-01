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

# Source files
SOURCES = $(wildcard *.cpp) $(wildcard BoosterStructures/*.cpp) \
          $(wildcard CheckAdjacentTemplate/*.cpp) $(wildcard CityStructures/*.cpp) \
          $(wildcard CityStructures/Road/*.cpp) $(wildcard CityStructures/Industrial/*.cpp) \
          $(wildcard CityStructures/Residential/*.cpp) $(wildcard CityStructures/Commercial/*.cpp) \
          $(wildcard CityStructures/Landmark/*.cpp) $(wildcard Factory/*.cpp) \
          $(wildcard PoliticalSystem/*.cpp) $(wildcard SatisfactionHandler/*.cpp)

# Object files (replace .cpp with .o for each source)
OBJECTS = $(SOURCES:.cpp=.o)

# Executable name
TARGET = program

# Build target
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)

# Clean up object files and executable
clean:
	rm -f $(OBJECTS) $(TARGET)

# Run the program
run: $(TARGET)
	./$(TARGET)
