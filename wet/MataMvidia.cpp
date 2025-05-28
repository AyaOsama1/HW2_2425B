//
// Created by abush on 5/28/2025.
//

#include "MataMvidia.h"

MataMvidia :: MataMvidia (const MataMvidia& other) {
    this -> numOfFrames = other.numOfFrames;
    this -> film =new Matrix [other.numOfFrames];
    for (int i = 0; i < numOfFrames; i++) {
        this -> film [i] = other.film[i];
    }
    this -> nameOfFilm = other.nameOfFilm;
    this ->nameOfMaker = other.nameOfMaker;
}
MataMvidia& MataMvidia :: operator= (const MataMvidia& other) {
    if (other.numOfFrames != this -> numOfFrames) {
        this -> film (new Matrix* [other.numOfFrames]);
    }
    for (int i = 0; i < numOfFrames; i++) {
        this -> film [i] = other.film[i];
    }
    this -> numOfFrames = other.numOfFrames;
    this -> nameOfFilm = other.nameOfFilm;
    this ->nameOfMaker = other.nameOfMaker;
}
