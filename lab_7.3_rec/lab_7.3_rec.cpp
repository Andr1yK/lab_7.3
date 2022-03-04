#include <iostream>
#include <iomanip>

#include "subFunctions.hpp"

using namespace std;

#pragma region PROTOTYPES
void RemoveEmpty(
  int** matrix,
  int& rowsCount, int& columnsCount
);

void RemoveEmptyRows(
  int** matrix,
  int& rowsCount, const int columnsCount,
  int currentRow
);

bool hasRowOnleZero(
  int** matrix,
  const int columnsCount,
  const int currentRow, const int currentColumn
);

void DeleteRow(
  int** matrix,
  int& rowsCount,
  const int rowIndex
);

void CopyRow(
  int** fromMatrix, int** toMatrix,
  const int indexToDelete,
  const int rowsCount,
  const int currentRowFrom, int currentRowTo
);

void RemoveEmptyColumns(
  int** matrix,
  const int rowsCount, int& columnsCount,
  int currentColumn
);

bool hasColumnOnleZero(
  int** matrix,
  const int rowsCount,
  const int currentRow, const int currentColumn
);

void MoveColumns(
  int** matrix,
  const int rowCount, int& columnCount,
  const int startIndex
);

void SwapColumns(
  int** matrix,
  const int rowCount,
  const int currentRow, const int currentColumn
);

int FindPositiveNumber(
  int** matrix,
  const int rowsCount, int columnsCount,
  const int currentRow = 0
);

int FindPositiveNumberRow(
  int** matrix,
  const int columnsCount,
  const int currentRow, const int currentColumn
);
#pragma endregion

int main()
{
  srand((unsigned)time(NULL));

  int Low = 0;
  int High = 1;

  int rowsCount;
  int columnCount;

  char mode;

  cout << "rowsCount = "; cin >> rowsCount;
  cout << "collumnCount = "; cin >> columnCount;

  cout << "Set mode (a - auto | m - munual): "; cin >> mode;

  int** matrix = new int* [rowsCount];
  for (int i = 0; i < rowsCount; i++)
    matrix[i] = new int[columnCount];

  if (mode == 'm') {
    ManualFillMatrix(matrix, rowsCount, columnCount);
  }
  else {
    AutoFillMatrix(matrix, rowsCount, columnCount, Low, High);
  }

  Print(matrix, rowsCount, columnCount);

  cout << "First positive number in row #" 
    << FindPositiveNumber(matrix, rowsCount, columnCount)
    << endl;

  RemoveEmpty(matrix, rowsCount, columnCount);

  Print(matrix, rowsCount, columnCount);

  for (int row = 0; row < rowsCount; row++)
    delete[] matrix[row];

  delete[] matrix;

  return 0;
}

void RemoveEmpty(
  int** matrix,
  int& rowsCount, int& columnsCount
) {
  RemoveEmptyRows(matrix, rowsCount, columnsCount, 0);
  RemoveEmptyColumns(matrix, rowsCount, columnsCount, 0);
}

// Remove Empty Rows
void RemoveEmptyRows(
  int** matrix,
  int& rowsCount, const int columnsCount,
  int currentRow
) {
  if (hasRowOnleZero(matrix, columnsCount, currentRow, 0)) {
    DeleteRow(matrix, rowsCount, currentRow);
    currentRow--;
  }

  if (currentRow < rowsCount - 1)
    RemoveEmptyRows(matrix, rowsCount, columnsCount, currentRow + 1);
}

bool hasRowOnleZero(
  int** matrix,
  const int columnsCount,
  const int currentRow, const int currentColumn
) {
  if (matrix[currentRow][currentColumn] != 0)
    return false;

  if (currentColumn < columnsCount - 1)
    return hasRowOnleZero(matrix, columnsCount, currentRow, currentColumn + 1);

  return true;
}

void DeleteRow(
  int** matrix,
  int& rowsCount, const int rowIndex
) {
  delete[] matrix[rowIndex];

  int** temp = new int* [rowsCount - 1];

  CopyRow(matrix, temp, rowIndex, rowsCount, 0, 0);

  rowsCount = rowsCount - 1;

  for (int i = 0; i < rowsCount; ++i)
    matrix[i] = temp[i];
}

void CopyRow(
  int** fromMatrix, int** toMatrix,
  const int indexToDelete,
  const int rowsCount,
  const int currentRowFrom, int currentRowTo
) {
  if (currentRowFrom != indexToDelete)
    toMatrix[currentRowTo++] = fromMatrix[currentRowFrom];

  if (currentRowFrom < rowsCount - 1)
    CopyRow(
      fromMatrix, toMatrix,
      indexToDelete,
      rowsCount,
      currentRowFrom + 1, currentRowTo
    );
};

// Remove Empty Columns
void RemoveEmptyColumns(
  int** matrix,
  const int rowsCount, int& columnsCount,
  int currentColumn
) {
  if (hasColumnOnleZero(matrix, rowsCount, 0, currentColumn)) {
    MoveColumns(matrix, rowsCount, columnsCount, currentColumn);
    currentColumn--;
    columnsCount--;
  }

  if (currentColumn < columnsCount - 1)
    RemoveEmptyColumns(matrix, rowsCount, columnsCount, currentColumn + 1);
}

bool hasColumnOnleZero(
  int** matrix,
  const int rowsCount,
  const int currentRow, const int currentColumn
) {
  if (matrix[currentRow][currentColumn] != 0)
    return false;

  if (currentRow < rowsCount - 1)
    return hasColumnOnleZero(matrix, rowsCount, currentRow + 1, currentColumn);

  return true;
}

void MoveColumns(
  int** matrix,
  const int rowCount, int& columnCount,
  const int currentColumn
) {
  SwapColumns(matrix, rowCount, 0, currentColumn);

  if (currentColumn < columnCount - 2)
    MoveColumns(matrix, rowCount, columnCount, currentColumn + 1);
}

void SwapColumns(
  int** matrix,
  const int rowCount,
  const int currentRow, const int currentColumn
) {
  const int temp = matrix[currentRow][currentColumn];
  matrix[currentRow][currentColumn] = matrix[currentRow][currentColumn + 1];
  matrix[currentRow][currentColumn + 1] = temp;

  if (currentRow < rowCount - 1)
    SwapColumns(matrix, rowCount, currentRow + 1, currentColumn);
}

#pragma region FindPositiveNumber
int FindPositiveNumber(
  int** matrix,
  const int rowsCount, int columnsCount,
  const int currentRow
) {
  int index = FindPositiveNumberRow(matrix, columnsCount, currentRow, 0);

  if (index != -1)
    return index + 1;

  if (currentRow < rowsCount - 1)
    return FindPositiveNumber(matrix, rowsCount, columnsCount, currentRow + 1);

  return index;
}

int FindPositiveNumberRow(
  int** matrix,
  const int columnsCount,
  const int currentRow, const int currentColumn
) {
  if (matrix[currentRow][currentColumn] > 0)
    return currentRow;

  if (currentColumn < columnsCount) {
    return FindPositiveNumberRow(matrix, columnsCount, currentRow, currentColumn + 1);
  }

  return -1;
}
#pragma endregion FindPositiveNumber
