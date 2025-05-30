//
// Created by abush on 5/27/2025.
//

#ifndef MATRIX_H
#define MATRIX_H
#include <iosfwd>

#endif //MATRIX_H
class Matrix {
    int rows ;
    int columns ;
    int* arr ;
    void copyMatrix(const Matrix& matrix);
    Matrix createMiniMatrix(const Matrix& matrix , const int Column_To_Ignore) const ;

public:

    Matrix ();
    Matrix (int rows ,  int columns ) ;
    Matrix (int rows ,  int columns , int values) ;
    Matrix(const Matrix& matrix) ;
    ~Matrix();


    int& operator()( int i , int j ) const;
    Matrix& operator*=(const Matrix& matrix);
    Matrix& operator+=( const Matrix& matrix );
    Matrix& operator-=( const Matrix& matrix );
    Matrix& operator*=( int scalar );

    Matrix operator-( const Matrix& matrix ) const;
    Matrix Matrix::operator+(const Matrix &matrix) const;
    Matrix operator*( int scalar ) const;
    Matrix& operator=( const Matrix& matrix );
    Matrix operator*(const Matrix& matrix) const;
    Matrix operator-()const;

    Matrix transpose()const ;
    double CalcFrobeniusNorm()const ;
    int CalcDeterminant()const ;
    Matrix& applyElementWiseOperator(const Matrix& matrix , const int factor);
    Matrix rotateClockwise ( Matrix& matrix ) const;
    Matrix rotateCounterClockwise ( Matrix& matrix ) const;


    bool isEqualSize(const Matrix& matrix) const;
    bool operator==( const Matrix& matrix ) const ;
    bool operator!=( const Matrix& matrix ) const ;

    friend Matrix operator* ( int scalar , Matrix& matrix );
    friend std::ostream& operator<<( std::ostream& os , const Matrix& matrix );
};