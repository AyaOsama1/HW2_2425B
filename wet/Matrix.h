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
public:
    Matrix ();
    Matrix (int rows ,  int columns ) ;
    Matrix (int rows ,  int columns , int values) ;
    int& operator()( int i , int j ) const;
    Matrix& operator=( const Matrix& matrix );
    Matrix& operator+=( const Matrix& matrix );
    Matrix operator-( const Matrix& matrix ) const;
    Matrix& operator-=( const Matrix& matrix );
    Matrix& applyElementWiseOperator(const Matrix& matrix , const int factor);
    bool isEqualSize(const Matrix& matrix) const;
    Matrix Matrix::operator+(const Matrix &matrix) const;
    Matrix operator*( int scalar ) const;
    Matrix& operator*=( int scalar );
    friend Matrix operator* ( int scalar , Matrix& matrix );
    bool operator==( const Matrix& matrix ) const ;
    bool operator!=( const Matrix& matrix ) const ;
    Matrix rotateClockwise ( Matrix& matrix ) const;
    Matrix rotateCounterClockwise ( Matrix& matrix ) const;
    Matrix(const Matrix& matrix) ;
    friend std::ostream& operator<<( std::ostream& os , const Matrix& matrix );
    ~Matrix();
};