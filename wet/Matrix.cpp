//
// Created by abush on 5/27/2025.
//

#include "Matrix.h"

Matrix :: Matrix () {
}
Matrix :: Matrix (int rows ,  int columns ) {
    this -> rows = rows;
    this -> columns = columns;
    this -> arr = new int[rows * columns]();
}
Matrix :: Matrix (int rows ,  int columns , int value) {
    this -> rows = rows;
    this -> columns = columns;
    this -> arr = new int [rows * columns];
    for (int i=0 ; i< (rows *columns); i++) {
        arr[i] = value ;
    }
}
int& operator()()( int i , int j ){ // returning a referrence and not just an int handels all cases cause if we want to write a value into that exact index we can not do that if we returned a copy so the reference make sure we're changing in the wanted place
    int place = ( i * columns )+ j ;// finding the index according to the giving info in the question i *width +j knowing that width = columns
    return arr[place] ;
}
