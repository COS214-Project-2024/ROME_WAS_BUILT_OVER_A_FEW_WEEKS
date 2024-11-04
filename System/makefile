# Compiler
CXX = g++
# Compiler flags
CXXFLAGS = -g -Wall
# Executable name
TARGET = program

# Source files
SOURCES = \
    ./BoosterStructures/Airport.cpp \
    ./CityStructures/Residential/Apartment.cpp \
    ./PoliticalSystem/Authoritarianism.cpp \
    ./BoosterStructures/BoosterStructures.cpp \
    CityHall.cpp \
    CityMap.cpp \
	./CheckAdjacentTemplate/CheckAdjacent.cpp \
    ./CityStructures/CityStructure.cpp \
    ./CityStructures/Landmark/Colosseum.cpp \
    ./CityStructures/Commercial/CommercialBuilding.cpp \
    ./PoliticalSystem/Communsim.cpp \
    ./CityStructures/Industrial/Concrete.cpp \
    ./CityStructures/Industrial/ConcreteGenerator.cpp \
    ./PoliticalSystem/Democracy.cpp \
    ./CityStructures/Residential/Estate.cpp \
    ./CityStructures/Industrial/Factory.cpp \
    ./CityStructures/Industrial/GeneratorDecorator.cpp \
    ./SatisfactionHandler/HighSatisfactionHandler.cpp \
    ./CityStructures/Road/HighTraffic.cpp \
    ./CityStructures//Residential/House.cpp \
    ./CityStructures/Industrial/IndustrialBuilding.cpp \
    ./CityStructures/Landmark/Landmark.cpp \
    ./SatisfactionHandler/LowSatisfactionHandler.cpp \
    ./CityStructures/Road/LowTraffic.cpp \
    main.cpp \
    ./CityStructures/Commercial/Mall.cpp \
    ./SatisfactionHandler/MediumSatisfactionHandler.cpp \
    ./CityStructures//Road/MediumTraffic.cpp \
    ./CityStructures/Commercial/Office.cpp \
    ./CityStructures/Landmark/Pantheon.cpp \
    ./CityStructures/Landmark/Park.cpp \
    ./PoliticalSystem/PoliticalSystem.cpp \
	./CityStructures/Industrial/Plant.cpp \
	./CityStructures/Industrial/PlantDecorator.cpp \
    ./CityStructures/Industrial/PowerPlant.cpp \
    ./BoosterStructures/Railway.cpp \
    ./CityStructures/Residential/ResidentialBuilding.cpp \
    ./CityStructures/Residential/ResidentialComplex.cpp \
    ./CityStructures/Road/Road.cpp \
    ./SatisfactionHandler/SatisfactionHandler.cpp \
    ./CityStructures/Industrial/SewagePlant.cpp \
    ./CityStructures/Commercial/Shop.cpp \
    ./CityStructures/Industrial/Steel.cpp \
    ./CityStructures/Industrial/SteelGenerator.cpp \
    ./CityStructures/Residential/Townhouse.cpp \
    ./CityStructures/Industrial/Warehouse.cpp \
    ./CityStructures/Industrial/WastePlant.cpp \
    ./CityStructures/Industrial/WaterPlant.cpp \
    ./CityStructures/Industrial/Wood.cpp \
    ./CityStructures/Industrial/WoodGenerator.cpp \
    ./CityStructures/Industrial/IndustrialFactory.cpp \
    ./CityStructures/Commercial/CommercialFactory.cpp \
    ./CityStructures/Residential/ResidentialFactory.cpp \
    ./CityStructures/Landmark/LandmarkFactory.cpp \

# Object files
OBJECTS = $(SOURCES:.cpp=.o)

# Default rule to build the executable
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)

# Rule to compile .cpp files to .o files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Run the program
run: $(TARGET)
	./$(TARGET)

# Clean up all generated files
clean:
	rm -f $(OBJECTS) $(TARGET)

# Rebuild everything
rebuild: clean $(TARGET)

