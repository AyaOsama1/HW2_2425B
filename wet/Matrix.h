//
// Created by abush on 5/27/2025.
//
#pragma once
#include <iostream>



class Matrix {
    int rows ;
    int columns ;
    int* arr ;
    void copyMatrix(const Matrix& matrix);
    Matrix createMiniMatrix(const Matrix& matrix , const int Column_To_Ignore) const ;
    Matrix& applyElementWiseOperator(const Matrix& matrix , const int factor);
    bool isEqualSize(const Matrix& matrix) const;
public:
     //constructors and destructors
    Matrix ();
    Matrix (int rows ,  int columns ) ;
    Matrix (int rows ,  int columns , int values) ;
    Matrix(const Matrix& matrix) ;
    ~Matrix();

    //basic Matrix operations
    int& operator()( int i , int j ) const;

    Matrix& operator*=(const Matrix& matrix);
    Matrix& operator+=( const Matrix& matrix );
    Matrix& operator-=( const Matrix& matrix );
    Matrix& operator*=( int scalar );

    Matrix operator-( const Matrix& matrix ) const;
    Matrix operator+(const Matrix &matrix) const;
    Matrix operator*( int scalar ) const;
    Matrix& operator=( const Matrix& matrix );
    Matrix operator*(const Matrix& matrix) const;
    Matrix operator-()const;

    //Utilities
    Matrix transpose()const ;
    double CalcFrobeniusNorm()const ;
    int CalcDeterminant()const ;
    Matrix rotateClockwise ( const Matrix& matrix ) const;
    Matrix rotateCounterClockwise ( const Matrix& matrix ) const;


    bool operator==( const Matrix& matrix ) const ;
    bool operator!=( const Matrix& matrix ) const ;

    friend Matrix operator* ( int scalar , const Matrix& matrix );
    friend std::ostream& operator<<( std::ostream& os , const Matrix& matrix );
};