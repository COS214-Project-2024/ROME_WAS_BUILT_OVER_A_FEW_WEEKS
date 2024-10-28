#ifndef DEMOCRACY_H
#define DEMOCRACY_H

#include <string>
#include <vector>

#include "PoliticalSystem.h"

class Democracy : public PoliticalSystem { 
public:
    Democracy();
    Democracy(std::string name, std::vector<std::string> politicalParties);
    void addPoliticalParty(std::string party);
    void removePoliticalParty(std::string party);
    ~Democracy();
};

#endif