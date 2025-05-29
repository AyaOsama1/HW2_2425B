//
// Created by abush on 5/27/2025.
//

#include "Matrix.h"
#include "Utilities.h"
#include <algorithm>
#include <filesystem>
#include <iostream>
using std::cout;
using std::endl;

Matrix::~Matrix() {
    delete[] this->arr;
}
void Matrix::copyMatrix(const Matrix &matrix) {
    this->columns = matrix.columns;
    this->rows = matrix.rows;
    this->arr = new int[this->columns * this->rows];
    for (int i = 0; i < this->columns * this->rows ; i++) {
        this->arr[i] = matrix.arr[i];
    }

}

Matrix::Matrix(const Matrix& matrix) {
    this->copyMatrix(matrix);
}

Matrix& Matrix::operator=(const Matrix& matrix) {
    if (this == &matrix)return *this;
    delete[] this->arr;
    this->copyMatrix(matrix);
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Matrix& matrix) {
    for (int i = 0 ; i < matrix.rows ; i++) {
        os << "|";
        for (int j = 0 ; j <  matrix.columns; j++) {
                         os << matrix.arr[i * matrix.columns + j] << "|";
        }
       os << endl;
    }
    return os;
}

bool Matrix::isEqualSize(const Matrix& matrix) const {
    const int thisSize = this->columns * this->rows;
    const int matrixSize = matrix.columns * matrix.rows;
    return thisSize == matrixSize;
}

Matrix &Matrix::applyElementWiseOperator(const Matrix& matrix , const int factor) {
    if (!isEqualSize(matrix)) {
        exitWithError( MatamErrorType::UnmatchedSizes);
    }

    for (int i = 0 ; i < this->rows * this->columns ; i++) {

            this->arr[i] += (factor * matrix.arr[i]);

    }
    return *this;
}


Matrix& Matrix::operator+=(const Matrix& matrix) {
    this->applyElementWiseOperator(matrix,1);
    return *this;

}

Matrix Matrix::operator+(const Matrix& matrix) const {
    if (!isEqualSize(matrix)) {
        exitWithError( MatamErrorType::UnmatchedSizes);
    }
    Matrix result(*this);
    result += matrix;
    return result;

}


Matrix& Matrix::operator-=(const Matrix &matrix) {
    this->applyElementWiseOperator(matrix,-1);
    return *this;

}
Matrix Matrix::operator-(const Matrix &matrix) const {

    if (!isEqualSize(matrix)) {
        exitWithError( MatamErrorType::UnmatchedSizes);
    }
    Matrix result(*this);
    result -= matrix;
    return result;

}


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
// this function first prints the values inside the columns upwards like the last value in the first column
// first and the first value in the first row last then moves to the next column
// in that way we rotate the matrix in a clock wise way
Matrix Matrix :: rotateClockwise ( Matrix& matrix ){
    int i =0;// index for the rotated matrix indexes
    int indexLastRow = (columns * rows) -  (this -> columns ) ;
    Matrix rotatedMatrix (this -> columns , this -> rows, 0);
    while (indexLastRow < this -> columns * this -> rows) {
    for (int k = matrix.arr[ indexLastRow ] ; k >= 0  ; k -= this -> columns){
            rotatedMatrix.arr[i] = matrix.arr[k] ;
            i++;
        }
        indexLastRow = indexLastRow + 1 ;
    }
    return rotatedMatrix ;
}
//we copy now from the last column and going back to the first one ; reading from the rows also from last
//row to the first one
Matrix Matrix :: rotateCounterClockwise ( Matrix& matrix ) {
    int i =0;// index for the rotated matrix indexes
    int indexLastColumn = columns - 1 ;
    Matrix rotatedMatrix (this -> columns , this -> rows, 0);
    while (indexLastColumn < this -> columns * this -> rows) {
        for (int k = matrix.arr[ indexLastColumn ] ; k < (this ->columns * rows)  ; k += this -> columns){
            rotatedMatrix.arr[i] = matrix.arr[k] ;
            i++;
        }
        indexLastColumn = indexLastColumn - 1 ;
    }
    return rotatedMatrix ;
}