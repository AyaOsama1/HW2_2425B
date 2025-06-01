//
// Created by abush on 5/28/2025.
//

#include "MataMvidia.h"
#define ZERO 0




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

void MataMvidia::moveFrames(const Matrix* from ,  Matrix* to , const int startIndix, const int endIndix ) {
    for (int i = startIndix; i < endIndix ; i++) {
        to[i] = from[i];
    }
}





MataMvidia& MataMvidia::operator+=(const Matrix& matrix) {
    Matrix* newFrames = new Matrix[this->frameCount + 1];
   moveFrames(this->frames, newFrames, ZERO, this->frameCount);
    newFrames[this->frameCount] = matrix;
    delete[] this->frames;
    this->frames = newFrames;
    this->frameCount++;
    return *this;
}


MataMvidia& MataMvidia::operator+=(const MataMvidia& other ) {
    for (int i = 0 ; i < other.frameCount ; i++) {
        *this += other.frames[i];
    }
    return *this;

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
