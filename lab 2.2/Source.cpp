#include "Matrix.h"
#include <iostream>
#include <Windows.h>

using namespace std;

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    // Створення об'єктів класу Matrix
    Matrix m1(2, 2); 
    Matrix m2(2, 2); 

    // Введення елементів першої матриці
    cout << "Введіть елементи першої матриці (2x2):" << endl;
    cin >> m1;

    // Виведення першої матриці
    cout << "Перша матриця:" << endl << m1 << endl;

    // Створення масиву об'єктів класу Matrix
    const int size = 3;
    Matrix array[size] = { Matrix(2, 2), Matrix(3, 3), Matrix(4, 4) };

    // Введення елементів другої матриці
    cout << "Введіть елементи другої матриці (2x2):" << endl;
    cin >> m2;

    // Виведення другої матриці
    cout << "Друга матриця:" << endl << m2 << endl;

    // Демонстрація операцій над матрицями
    Matrix sum = m1 + m2;
    Matrix difference = m1 - m2;
    Matrix product = m1 * m2;

    // Виведення результатів операцій
    cout << "Сума матриць:" << endl << sum << endl;
    cout << "Різниця матриць:" << endl << difference << endl;
    cout << "Добуток матриць:" << endl << product << endl;

    return 0;
}