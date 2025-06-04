
#pragma once

#include <iostream>

using std::string;
enum DEVIL_FRUIT {
    GUMGUM,
    FLOWERFLOWER,
    CHOPCHOP
};
class Pirate {
private:
    string name;
    int Bounty;
    DEVIL_FRUIT fruit;

public:
    Pirate(const string& name , int Bounty);
    int getBounty() const;
    void setBounty(int Bounty);

    ~Pirate() = default;
    void setName(const string& name);

    string getName();

    friend std::ostream &operator<<(std::ostream &os, const Pirate &pirate);
};
