#include "Matrix.h"
#include <iostream>
#include <Windows.h>

using namespace std;

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    // ��������� ��'���� ����� Matrix
    Matrix m1(2, 2); 
    Matrix m2(2, 2); 

    // �������� �������� ����� �������
    cout << "������ �������� ����� ������� (2x2):" << endl;
    cin >> m1;

    // ��������� ����� �������
    cout << "����� �������:" << endl << m1 << endl;

    // ��������� ������ ��'���� ����� Matrix
    const int size = 3;
    Matrix array[size] = { Matrix(2, 2), Matrix(3, 3), Matrix(4, 4) };

    // �������� �������� ����� �������
    cout << "������ �������� ����� ������� (2x2):" << endl;
    cin >> m2;

    // ��������� ����� �������
    cout << "����� �������:" << endl << m2 << endl;

    // ������������ �������� ��� ���������
    Matrix sum = m1 + m2;
    Matrix difference = m1 - m2;
    Matrix product = m1 * m2;

    // ��������� ���������� ��������
    cout << "���� �������:" << endl << sum << endl;
    cout << "г����� �������:" << endl << difference << endl;
    cout << "������� �������:" << endl << product << endl;

    return 0;
}