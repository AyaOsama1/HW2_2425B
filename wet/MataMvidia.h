//
// Created by abush on 5/28/2025.
//

#pragma once


class MataMvidia {
    int numOfFrames;
    Matrix* film;
    string nameOfFilm;
    string nameOfMaker;
    MataMvidia (const MataMvidia& other);
    MataMvidia& operator= (const MataMvidia& other);
};
