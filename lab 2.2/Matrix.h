// Matrix.h
#pragma once
#include <iostream>

class Matrix {
    int** matrix;
    int rows;
    int cols;

public:
    // Конструктори
    Matrix();
    Matrix(int rows, int cols);
    Matrix(const Matrix& other);

    // Деструктор
    ~Matrix();

    // Оператор присвоєння
    Matrix& operator=(const Matrix& other);

    // Операції над матрицями
    Matrix operator+(const Matrix& other) const;
    Matrix operator-(const Matrix& other) const;
    Matrix operator*(const Matrix& other) const;
    Matrix& operator+=(const Matrix& other);
    Matrix& operator-=(const Matrix& other);
    Matrix& operator*=(const Matrix& other);

    // Перевантаження потокових операцій
    friend std::istream& operator>>(std::istream& is, Matrix& obj);
    friend std::ostream& operator<<(std::ostream& os, const Matrix& obj);
};
