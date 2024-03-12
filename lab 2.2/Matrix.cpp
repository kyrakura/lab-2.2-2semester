// Matrix.cpp
#include "Matrix.h"
#include <Windows.h>

// Конструктор за замовчуванням
Matrix::Matrix() : matrix(nullptr), rows(0), cols(0) {}

// Конструктор з вказанням розмірів матриці
Matrix::Matrix(int rows, int cols) : rows(rows), cols(cols) {
    matrix = new int* [rows];
    for (int i = 0; i < rows; ++i) {
        matrix[i] = new int[cols];
    }
}

// Конструктор копіювання
Matrix::Matrix(const Matrix& other) : rows(other.rows), cols(other.cols) {
    matrix = new int* [rows];
    for (int i = 0; i < rows; ++i) {
        matrix[i] = new int[cols];
        for (int j = 0; j < cols; ++j) {
            matrix[i][j] = other.matrix[i][j];
        }
    }
}

// Деструктор
Matrix::~Matrix() {
    if (matrix != nullptr) {
        for (int i = 0; i < rows; ++i) {
            delete[] matrix[i];
        }
        delete[] matrix;
    }
}

// Оператор присвоєння
Matrix& Matrix::operator=(const Matrix& other) {
    if (this == &other)
        return *this;

    // Видалення поточних даних
    for (int i = 0; i < rows; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;

    // Копіювання нових даних
    rows = other.rows;
    cols = other.cols;
    matrix = new int* [rows];
    for (int i = 0; i < rows; ++i) {
        matrix[i] = new int[cols];
        for (int j = 0; j < cols; ++j) {
            matrix[i][j] = other.matrix[i][j];
        }
    }
    return *this;
}

// Операція додавання
Matrix Matrix::operator+(const Matrix& other) const {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    if (rows != other.rows || cols != other.cols) {
        // Обробка помилки: матриці мають мати однакові розміри для додавання
        throw std::invalid_argument("Матриці повинні мати однакові розміри для складання:");
    }

    Matrix result(rows, cols);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result.matrix[i][j] = matrix[i][j] + other.matrix[i][j];
        }
    }
    return result;
}

// Операція віднімання
Matrix Matrix::operator-(const Matrix& other) const {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    if (rows != other.rows || cols != other.cols) {
        // Обробка помилки: матриці мають мати однакові розміри для віднімання
        throw std::invalid_argument("Матриці повинні мати однакові розміри для віднімання:");
    }

    Matrix result(rows, cols);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result.matrix[i][j] = matrix[i][j] - other.matrix[i][j];
        }
    }
    return result;
}

// Операція множення
Matrix Matrix::operator*(const Matrix& other) const {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    if (cols != other.rows) {
        // Обробка помилки: кількість стовпців першої матриці повинна дорівнювати кількості рядків другої матриці для множення
        throw std::invalid_argument("Кількість стовпців у першій матриці має дорівнювати кількості рядків у другій матриці для множення:");
    }

    Matrix result(rows, other.cols);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < other.cols; ++j) {
            result.matrix[i][j] = 0;
            for (int k = 0; k < cols; ++k) {
                result.matrix[i][j] += matrix[i][k] * other.matrix[k][j];
            }
        }
    }
    return result;
}

// Операція додавання з присвоєнням
Matrix& Matrix::operator+=(const Matrix& other) {
    *this = *this + other;
    return *this;
}

// Операція віднімання з присвоєнням
Matrix& Matrix::operator-=(const Matrix& other) {
    *this = *this - other;
    return *this;
}

// Операція множення з присвоєнням
Matrix& Matrix::operator*=(const Matrix& other) {
    *this = *this * other;
    return *this;
}

// Перевантаження потокових операцій для введення матриці
std::istream& operator>>(std::istream& is, Matrix& obj) {
    for (int i = 0; i < obj.rows; ++i) {
        for (int j = 0; j < obj.cols; ++j) {
            is >> obj.matrix[i][j];
        }
    }
    return is;
}

// Перевантаження потокових операцій для виведення матриці
std::ostream& operator<<(std::ostream& os, const Matrix& obj) {
    for (int i = 0; i < obj.rows; ++i) {
        for (int j = 0; j < obj.cols; ++j) {
            os << obj.matrix[i][j] << " ";
        }
        os << std::endl;
    }
    return os;
}

