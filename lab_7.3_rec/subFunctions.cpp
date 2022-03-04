#include "subFunctions.hpp"

using namespace std;

#pragma region Auto_Fill
void AutoFillMatrix(
  int** matrix,
  const int rowsCount, const int columnsCount,
  const int Low, const int High,
  const int currentRow
) {
  AutoFillMatrixRow(matrix, columnsCount, Low, High, currentRow);

  if (currentRow < rowsCount - 1) {
    AutoFillMatrix(matrix, rowsCount, columnsCount, Low, High, currentRow + 1);
  }
}

void AutoFillMatrixRow(
  int** matrix,
  const int columnsCount,
  const int Low, const int High,
  const int currentRow, const int currentColumn
) {
  matrix[currentRow][currentColumn] = Low + rand() % (High - Low + 1);

  if (currentColumn < columnsCount - 1) {
    AutoFillMatrixRow(matrix, columnsCount, Low, High, currentRow, currentColumn + 1);
  }
}
#pragma endregion Auto_Fill

#pragma region Manual_Fill
void ManualFillMatrix(
  int** matrix,
  const int rowsCount, const int columnsCount,
  const int currentRow
) {
  ManualFillMatrixRow(matrix, columnsCount, currentRow);
  cout << endl;

  if (currentRow < rowsCount - 1) {
    ManualFillMatrix(matrix, rowsCount, columnsCount, currentRow + 1);
  }
}

void ManualFillMatrixRow(
  int** matrix,
  const int columnsCount,
  const int currentRow, const int currentColumn
) {
  cout << "a[" << currentRow << "][" << currentColumn << "] = ";
  cin >> matrix[currentRow][currentColumn];

  if (currentColumn < columnsCount - 1) {
    ManualFillMatrixRow(matrix, columnsCount, currentRow, currentColumn + 1);
  }
}
#pragma endregion Manual_Fill

#pragma region Print
void Print(
  int** matrix,
  const int rowsCount, const int columnsCount,
  const int currentRow
) {
  PrintRow(matrix, columnsCount, currentRow);

  if (currentRow < rowsCount - 1) {
    Print(matrix, rowsCount, columnsCount, currentRow + 1);
  }
  else {
    cout << endl;
  }
}

void PrintRow(
  int** matrix,
  const int columnsCount,
  const int currentRow, const int currentColumn
) {
  cout << setw(4) << matrix[currentRow][currentColumn];

  if (currentColumn < columnsCount - 1) {
    PrintRow(matrix, columnsCount, currentRow, currentColumn + 1);
  }
  else {
    cout << endl;
  }
}

#pragma endregion Print