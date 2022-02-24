#include "pch.h"
#include "CppUnitTest.h"
#include "../lab_7.3/lab_7.3.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest731
{
	TEST_CLASS(UnitTest731)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			const int rowCountConst = 4;
			const int colCountConst = 4;

			int rowCount = rowCountConst;
			int colCount = colCountConst;

			int** matrix = new int* [rowCount];
			for (int i = 0; i < rowCount; i++)
				matrix[i] = new int[colCount];

			int matrixToCopy[rowCountConst][colCountConst] = {
				{4, 0, 0, 2},
				{3, 0, 1, 0},
				{0, 0, 0, 0},
				{1, 0, 3, 4},
			};

			for (int row = 0; row < rowCount; row++)
				for (int column = 0; column < colCount; column++)
					matrix[row][column] = matrixToCopy[row][column];

			int resultedArray[3][3] = {
				{4, 0, 2},
				{3, 1, 0},
				{1, 3, 4},
			};

			RemoveEmpty(matrix, rowCount, colCount);

			Assert::AreEqual(3, colCount);
			Assert::AreEqual(3, rowCount);

			for (int row = 0; row < rowCount; row++)
				for (int column = 0; column < colCount; column++) {
					wstring msg =
						L"\nError:\n matrix[" + to_wstring(row) + L"][" + to_wstring(column) + L"] = "
						+ to_wstring(matrix[row][column]) + L"\n" +

						L"resltedMatrix[" + to_wstring(row) + L"][" + to_wstring(column) + L"] = "
						+ to_wstring(resultedArray[row][column]);

					//Error:
					// matrix[r][c] = number
					// resltedMatrix[r][c] = number

					Assert::AreEqual(resultedArray[row][column], matrix[row][column], msg.c_str());
				}
		};
	};
};
