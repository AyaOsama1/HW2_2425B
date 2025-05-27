//
// Created by abush on 5/27/2025.
//

#ifndef MATRIX_H
#define MATRIX_H

#endif //MATRIX_H
class Matrix {
    int rows = 0  ;
    int columns = 0 ;
    int* arr = nullptr;
    Matrix ();
    Matrix (int rows ,  int columns ) ;
    Matrix (int rows ,  int columns , int values) ;
   // should check if we even need this  ~Matrix () ;
    int& operator()( int i , int j );
    Matrix operator*( int scalar );
    Matrix& operator*=( int scalar );
    friend Matrix operator* ( int scalar , Matrix& matrix );
    bool operator==( const Matrix& matrix ) const ;
    bool operator!=( const Matrix& matrix ) const ;
    Matrix rotateClockwise ( Matrix& matrix );
    Matrix rotateCounterClockwise ( Matrix& matrix );

};