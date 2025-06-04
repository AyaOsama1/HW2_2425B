//
// Created by abush on 5/28/2025.
//

#pragma once
#include "Matrix.h"
using namespace std;
#include <string>

class MataMvidia {
    int frameCount;
    Matrix* frames;
    string title;
    string directorName;
    void moveFrames(const Matrix* from ,  Matrix* to , const int startIndix, const int endIndix ) ;

    public:

    //constructors and destructors
    MataMvidia (const MataMvidia& other);
    MataMvidia::MataMvidia(const string& title, const string& directorName, const Matrix *frames, const int frameCount) ;
    ~MataMvidia();


    //basic operators
    MataMvidia& operator= (const MataMvidia& other);
    MataMvidia& operator+=(const Matrix& matrix);
    MataMvidia& operator+=(const MataMvidia& other);
    MataMvidia& operator[] (const int index) ;
    MataMvidia operator+(const MataMvidia other) const;

};
