// Matrix.cpp
#include "Matrix.h"
#include <Windows.h>

// ����������� �� �������������
Matrix::Matrix() : matrix(nullptr), rows(0), cols(0) {}

// ����������� � ��������� ������ �������
Matrix::Matrix(int rows, int cols) : rows(rows), cols(cols) {
    matrix = new int* [rows];
    for (int i = 0; i < rows; ++i) {
        matrix[i] = new int[cols];
    }
}

// ����������� ���������
Matrix::Matrix(const Matrix& other) : rows(other.rows), cols(other.cols) {
    matrix = new int* [rows];
    for (int i = 0; i < rows; ++i) {
        matrix[i] = new int[cols];
        for (int j = 0; j < cols; ++j) {
            matrix[i][j] = other.matrix[i][j];
        }
    }
}

// ����������
Matrix::~Matrix() {
    if (matrix != nullptr) {
        for (int i = 0; i < rows; ++i) {
            delete[] matrix[i];
        }
        delete[] matrix;
    }
}

// �������� ���������
Matrix& Matrix::operator=(const Matrix& other) {
    if (this == &other)
        return *this;

    // ��������� �������� �����
    for (int i = 0; i < rows; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;

    // ��������� ����� �����
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

// �������� ���������
Matrix Matrix::operator+(const Matrix& other) const {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    if (rows != other.rows || cols != other.cols) {
        // ������� �������: ������� ����� ���� ������� ������ ��� ���������
        throw std::invalid_argument("������� ������ ���� ������� ������ ��� ���������:");
    }

    Matrix result(rows, cols);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result.matrix[i][j] = matrix[i][j] + other.matrix[i][j];
        }
    }
    return result;
}

// �������� ��������
Matrix Matrix::operator-(const Matrix& other) const {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    if (rows != other.rows || cols != other.cols) {
        // ������� �������: ������� ����� ���� ������� ������ ��� ��������
        throw std::invalid_argument("������� ������ ���� ������� ������ ��� ��������:");
    }

    Matrix result(rows, cols);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result.matrix[i][j] = matrix[i][j] - other.matrix[i][j];
        }
    }
    return result;
}

// �������� ��������
Matrix Matrix::operator*(const Matrix& other) const {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    if (cols != other.rows) {
        // ������� �������: ������� �������� ����� ������� ������� ���������� ������� ����� ����� ������� ��� ��������
        throw std::invalid_argument("ʳ������ �������� � ������ ������� �� ���������� ������� ����� � ����� ������� ��� ��������:");
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

// �������� ��������� � ����������
Matrix& Matrix::operator+=(const Matrix& other) {
    *this = *this + other;
    return *this;
}

// �������� �������� � ����������
Matrix& Matrix::operator-=(const Matrix& other) {
    *this = *this - other;
    return *this;
}

// �������� �������� � ����������
Matrix& Matrix::operator*=(const Matrix& other) {
    *this = *this * other;
    return *this;
}

// �������������� ��������� �������� ��� �������� �������
std::istream& operator>>(std::istream& is, Matrix& obj) {
    for (int i = 0; i < obj.rows; ++i) {
        for (int j = 0; j < obj.cols; ++j) {
            is >> obj.matrix[i][j];
        }
    }
    return is;
}

// �������������� ��������� �������� ��� ��������� �������
std::ostream& operator<<(std::ostream& os, const Matrix& obj) {
    for (int i = 0; i < obj.rows; ++i) {
        for (int j = 0; j < obj.cols; ++j) {
            os << obj.matrix[i][j] << " ";
        }
        os << std::endl;
    }
    return os;
}

