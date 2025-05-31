//
// Created by abush on 5/28/2025.
//

#include "MataMvidia.h"

MataMvidia :: MataMvidia (const MataMvidia& other) {
    this -> title = other.title;
    this -> frames =new Matrix [other.frameCount];
    for (int i = 0; i < frameCount; i++) {
        this -> frames [i] = other.frames[i];
    }
    this ->directorName = other.directorName;
}
MataMvidia& MataMvidia :: operator= (const MataMvidia& other) {
    if (other.frameCount != this -> frameCount) {
        this -> frames (new Matrix* [other.frameCount]);
    }
    for (int i = 0; i < frameCount; i++) {
        this -> frames [i] = other.frames[i];
    }
    this -> frameCount = other.frameCount;
    this -> title = other.title;
    this ->directorName = other.directorName;
    return *this;
}
