//
// Created by abush on 5/28/2025.
//

#include "MataMvidia.h"




MataMvidia::MataMvidia(const string& title, const string& directorName, const Matrix *frames, const int frameCount) {
    this->title = title;
    this->directorName = directorName;
    this->frameCount = frameCount;
    this->frames = new Matrix[frameCount];
    for (int i = 0; i < frameCount; i++) {
        this->frames[i] = frames[i];
    }

}

MataMvidia::~MataMvidia() {
    delete[] this->frames;
}


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
