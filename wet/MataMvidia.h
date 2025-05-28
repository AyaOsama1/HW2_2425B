//
// Created by abush on 5/28/2025.
//

#ifndef MATAMVIDIA_H
#define MATAMVIDIA_H
#include "Matrix.h"
#include <string>

#endif //MATAMVIDIA_H
class MataMvidia {
    int numOfFrames;
    Matrix* film;    
    string nameOfFilm;
    string nameOfMaker;
    MataMvidia (const MataMvidia& other);
    MataMvidia& operator= (const MataMvidia& other);
};
