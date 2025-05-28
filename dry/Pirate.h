
#pragma once

#include <iostream>

using std::string;

class Pirate {
private:
    string name;
    int Bounty;

public:
    Pirate(const string& name , int Bounty);
    int getBounty() const;
    void setBounty(int Bounty);

    ~Pirate() = default;
    void setName(const string& name);

    string getName();
    void printBounty(int Bounty);

    friend std::ostream &operator<<(std::ostream &os, const Pirate &pirate);
};
