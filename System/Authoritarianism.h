#ifndef AUTHORITARIANISM_H
#define AUTHORITARIANISM_H

#include <string>
#include <vector>
#include "PoliticalSystem.h"   

class Authoritarianism : public PoliticalSystem {
public:
    Authoritarianism();
    Authoritarianism(std::string name, std::vector<std::string> politicalParties);
    void addPoliticalParty(std::string party);
    void removePoliticalParty(std::string party);
    ~Authoritarianism();
};

#endif