
#include "Pirate.h"


 Pirate::Pirate(const string& name, int Bounty) : name(name) , Bounty(Bounty) {}


void Pirate::setName(const string& name){
    this->name = name;
}

std::string Pirate::getName(){
    return name;
}


std::ostream &operator<<(std::ostream &os, const Pirate &pirate){
    os << pirate.name;
     os << pirate.fruit;
    return os;
}

 void Pirate::setBounty(int Bounty){
 this->Bounty = Bounty;

}

 int Pirate::getBounty() const{
  return Bounty;
 }

