#include <iostream>
#include "Pirate.h"
#include <cstring>

using std::cout, std::endl;


int main() {

    Pirate luffy("Luffy");
    Pirate zoro("Zoro");

    const int crewSize = 2;
    Pirate strawHatCrew[2] = {luffy, zoro};
    // the problem was in line 15 that command called a default constructor in Pirate while Pirate doesn't have one
    // what I did is : put the values as in assignment and in that way no need to use a default constructor and the
    // values are in the places that we wanted
    cout << "Straw Hat crew contains:" << endl;
    for (int i = 0; i < crewSize; i++) {
        cout << strawHatCrew[i] << endl;
    }
    return 0;
}
