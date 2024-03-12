#include "pch.h"
#include "CppUnitTest.h"
#include "../lab 2.2/Matrix.h"
#include "D:\project C++ 2\lab 2.2\lab 2.2\Matrix.cpp"
#include "D:\project C++ 2\lab 2.2\lab 2.2\Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int rows = 2;
			int cols = 4;
			// Створюємо масив об'єктів класу Matrix
			const int size = 3;
			Matrix array[size] = { Matrix(2, 2), Matrix(3, 3), Matrix(4, 4) };
		}
	};
}