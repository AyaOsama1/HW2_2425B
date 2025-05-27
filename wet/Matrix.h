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
    Matrix (int rows = 0 ,  int columns = 0) ;
    Matrix (int rows = 0 ,  int columns = 0 , int values=0) ;
    ~Matrix () ;
    int& operator()()( int i , int j );
    Matrix& operator*( int b );


};