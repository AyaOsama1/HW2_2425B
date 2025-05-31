//
// Created by abush on 5/28/2025.
//

#pragma once
#include "Matrix.h"
using namespace std;
#include <string>

class MataMvidia {
    int numOfFrames;
    Matrix* film;
    string nameOfFilm;
    string nameOfMaker;

    public:

    //constructors and destructors
    MataMvidia (const MataMvidia& other);

    //basic operators
    MataMvidia& operator= (const MataMvidia& other);
};
