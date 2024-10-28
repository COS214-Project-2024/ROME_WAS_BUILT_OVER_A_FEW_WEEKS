#ifndef COMMUNSIM_H
#define COMMUNSIM_H

#include <string>
#include <vector>

#include "PoliticalSystem.h"

class Communsim : public PoliticalSystem { 
public:
    Communsim();
    Communsim(std::string name, std::vector<std::string> politicalParties);
    void addPoliticalParty(std::string party);
    void removePoliticalParty(std::string party);
    ~Communsim();
};

#endif