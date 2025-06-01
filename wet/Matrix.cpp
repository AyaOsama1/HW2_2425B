//
// Created by abush on 5/27/2025.
//

#include "Matrix.h"
#include "Utilities.h"
#include <cmath>
#include <filesystem>
#include <iostream>
#define MINUS_ONE -1
#define ONE 1
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
    this->applyElementWiseOperator(matrix,ONE);
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
    this->applyElementWiseOperator(matrix,MINUS_ONE);
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


Matrix& Matrix::operator*=(const Matrix &matrix) {
    if (this->columns != matrix.rows) {
        exitWithError( MatamErrorType::UnmatchedSizes);
    }
    int* result = new int[this->rows * matrix.columns];
    for (int i = 0 ; i < this->rows ; i++) {
        for (int j = 0 ; j < matrix.columns ; j++) {
            result[i * matrix.columns + j] = 0;
            for (int k = 0 ; k < this->rows ; k++) {
                result[i * matrix.columns + j]  += (*this)(i , k) * matrix(k , j);
            }

        }
    }
   delete[] this->arr;
    this->arr = result;
    this->columns = matrix.columns;
    return *this;
}

Matrix Matrix::operator*(const Matrix& matrix) const {
    Matrix result(*this);
    result *= matrix;
    return result;

}

Matrix Matrix::operator-() const {
    Matrix result(*this);
    result *= -1;
    return result;

}
Matrix Matrix::transpose()const {
    Matrix result( this->columns , this->rows);
    for (int i = 0 ; i < this->rows ; i++) {
        for (int j = 0 ; j <  this->columns ; j++) {
            result(j , i) = (*this)(i , j);
        }
    }
    return result;

}

double Matrix::CalcFrobeniusNorm()const {
    int sum = 0 ;
    for (int i = 0 ; i < this->columns * this->rows ; i++) {
        sum += this->arr[i] * this->arr[i] ;
    }
    return sqrt(sum);
}

Matrix Matrix::createMiniMatrix(const Matrix& matrix , const int Column_To_Ignore) const {
    Matrix result(matrix.rows - 1, matrix.columns - 1);
    for (int i = 1 ; i < matrix.rows ; i++) {
        for (int j = 1 ; j < matrix.columns ; j++) {
            if ( j == Column_To_Ignore) {
                result(i - 1 , j - 1) = matrix(i , j + 1);

            } else {
                result(i - 1 , j - 1) = matrix(i , j );
            }
        }
    }

    return result;

}

int Matrix::CalcDeterminant()const {
    int factor = 0  , determinant = 0;
    if (this->columns != this->rows) {
        exitWithError(MatamErrorType::NotSquareMatrix);
    }
    if (this->columns == 1) {
        return (*this)(1 , 1);
    }
    if (this->columns == 2) {
        return ( (*this)(1 , 1) * (*this)(2 , 2) ) - ((*this)(1 , 2) * (*this)(2 , 1));
    }
    if (this->columns >= 3) {
       for (int j = 0 ; j < this->columns ; j++) {
           if ( j % 2 == 0)factor = 1;
           else factor = -1;
           Matrix MiniMatrix = createMiniMatrix(*this, j);
           determinant += factor*(*this)(0 , j) * MiniMatrix.CalcDeterminant();

       }

    }
    return determinant;

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
int& Matrix::operator()( int i , int j ) const { // returning a reference and not just an int handles all cases cause if we want to write a value into that exact index we can not do that if we returned a copy so the reference make sure we're changing in the wanted place
    int place = ( i * columns )+ j ;// finding the index according to the giving info in the question i *width +j knowing that width = columns
    return arr[place] ;
}
Matrix& Matrix::operator*= ( int scalar ) {
    // it will take the matrix that's on the left as this object call the *= in the class from type matrix
    // and take the scalar on the right as a value that the matrix takes and multiply as in this code
    for (int i = 0 ; i < (rows * columns); i++) {
        arr [i]= arr[i] * scalar ;
    }
    return *this;
}

Matrix Matrix::operator* ( int scalar ) const {
    // it will take the matrix that's on the left as this object , call the * in the class from type matrix
    // and take the scalar on the right as a value that the matrix takes and multiply as in this code
    Matrix result (rows ,columns,0);
    for (int i = 0 ; i < (rows * columns); i++) {
        result.arr[i] = this -> arr [i] * scalar ;
    }
    return result;
}

Matrix operator* ( int scalar , const Matrix& matrix ) {
    Matrix result (matrix.rows ,matrix.columns,0);
    for (int i = 0 ; i < (matrix.rows * matrix.columns); i++) {
        result.arr[i] = matrix.arr [i] * scalar ;
    }
    return result;
}// when there is a scalar from the right then the function searches for an
//integer function that have * operator and take matrix as a parameter there is no such function in
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
            exitWithError(MatamErrorType::UnmatchedSizes);
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
Matrix Matrix :: rotateClockwise ( Matrix& matrix ) const {
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
Matrix Matrix :: rotateCounterClockwise ( Matrix& matrix ) const {
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

Matrix Matrix :: rotateClockwise ( const Matrix& matrix ) const {
     const int resultColumns = matrix.rows , resultRows = matrix.columns;
    Matrix result(resultRows , resultColumns , 0);
    for (int i = 0 ; i < matrix.rows ; i++) {
        for (int j = 0 ; j <  matrix.columns ; j++) {
            result(j , i) = matrix(matrix.rows - i - 1, j );
        }
    }

    return result ;


}

Matrix Matrix:: rotateCounterClockwise ( const Matrix& matrix ) const {
    Matrix result = rotateClockwise(rotateClockwise(rotateClockwise(matrix)));
    return result ;
}








