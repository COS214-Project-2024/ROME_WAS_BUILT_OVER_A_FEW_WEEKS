#ifndef POLITICALSYSTEM_H
#define POLITICALSYSTEM_H

#include <string>
#include <vector>


class PoliticalSystem {
public:
    PoliticalSystem();
    PoliticalSystem(std::string name, std::vector<std::string> politicalParties);
    std::string getName();
    std::vector<std::string> getPoliticalParties();
    void addPoliticalParty(std::string party);
    void removePoliticalParty(std::string party);
    ~PoliticalSystem();

private:
    std::string name;
    std::vector<std::string> politicalParties;
};

#endif