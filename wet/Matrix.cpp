//
// Created by abush on 5/27/2025.
//

#include "Matrix.h"

Matrix :: Matrix () {
    rows = 0 ;
    columns = 0 ;
    arr = new int [0] ;
}
Matrix::Matrix (int rows ,  int columns ) {
    this -> rows = rows;
    this -> columns = columns;
    this -> arr = new int[rows * columns]();
}
 Matrix::Matrix (int rows ,  int columns , int value) {
    this -> rows = rows;
    this -> columns = columns;
    this -> arr = new int [rows * columns];
    for (int i=0 ; i< (rows *columns); i++) {
        arr[i] = value ;
    }
}
int& Matrix::operator()( int i , int j ){ // returning a referrence and not just an int handels all cases cause if we want to write a value into that exact index we can not do that if we returned a copy so the reference make sure we're changing in the wanted place
    int place = ( i * columns )+ j ;// finding the index according to the giving info in the question i *width +j knowing that width = columns
    return arr[place] ;
}
Matrix& Matrix::operator*= ( int scalar ) {
    // it will take the matrix that's on the left as this object call the *= in the class from type matrix
    // and take the sclar on the right as a value that the matrix takes and multiply as in this code
    for (int i = 0 ; i < (rows * columns); i++) {
        arr [i]= arr[i] * scalar ;
    }
    return *this;
}

Matrix Matrix::operator* ( int scalar ){
    // it will take the matrix that's on the left as this object , call the * in the class from type matrix
    // and take the scalar on the right as a value that the matrix takes and multiply as in this code
    Matrix result (rows ,columns,0);
    for (int i = 0 ; i < (rows * columns); i++) {
        result.arr[i] = this -> arr [i] * scalar ;
    }
    return result;
}

Matrix operator* ( int scalar , Matrix& matrix ) {
    Matrix result (matrix.rows ,matrix.columns,0);
    for (int i = 0 ; i < (matrix.rows * matrix.columns); i++) {
        result.arr[i] = matrix.arr [i] * scalar ;
    }
    return result;
}// when ther is a scalar from the right then the function searches for an integer function that have * operator and take matrix as a parameter there is no such function in
//the integer class so I declared this non member function to be used when there is scalar from the left

bool Matrix :: operator== ( const Matrix& matrix ) const {
    if ((this -> arr == nullptr && matrix.arr != nullptr) || (this -> arr != nullptr && matrix.arr == nullptr)) {
        return false;
    }
    if (this->rows != matrix.rows || this->columns != matrix.columns ) {
        return false;
    }
    for (int i = 0 ; i < (this->rows * this->columns); i++) {
        if (this->arr[i] != matrix.arr[i]) {
            return false;
        }
    }
    return true ;
}
bool Matrix :: operator!= ( const Matrix& matrix ) const {
    return !(*this == matrix) ;
}