#include <iostream>
#include <iomanip>

using namespace std;

void ManualFillMatrix(
  int** matrix, 
  const int rowsCount, const int columnsCount
);

void AutoFillMatrix(
  int** matrix,
  const int rowsCount, const int columnsCount,
  const int Low, const int High
);

void Print(
  int** matrix,
  const int rowsCount, const int columnsCount
);

void RemoveEmpty(
  int** matrix,
  int& rowsCount, int& columnsCount
);

void RemoveEmptyRows(
  int** matrix,
  int& rowsCount, const int columnsCount
);

void DeleteRow(
  int** matrix,
  int& rowsCount,
  const int rowIndex
);

void RemoveEmptyColumns(
  int** matrix,
  const int rowsCount, int& columnsCount
);

void MoveColumn(
  int** matrix, 
  const int rowCount, int& columnCount,
  const int startIndex
);

int FindPositiveNumber(
  int** matrix,
  const int rowsCount, const int columnsCount
);

int main()
{
  srand((unsigned)time(NULL));

  int Low = -1;
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

  cout << FindPositiveNumber(matrix, rowsCount, columnCount) << endl;

  RemoveEmpty(matrix, rowsCount, columnCount);

  Print(matrix, rowsCount, columnCount);

  for (int i = 0; i < rowsCount; i++)
    delete[] matrix[i];

  delete[] matrix;

  return 0;
}

void ManualFillMatrix(
  int** matrix, 
  const int rowsCount, const int columnsCount
) {
    for (int i = 0; i < rowsCount; i++)
    {
      for (int j = 0; j < columnsCount; j++)
      {
        cout << "a[" << i << "][" << j << "] = ";
        cin >> matrix[i][j];
      }
      cout << endl;
    }
}

void AutoFillMatrix(
  int** matrix,
  const int rowsCount, const int columnsCount,
  const int Low, const int High
) {
  for (int row = 0; row < rowsCount; row++)
    for (int column = 0; column < columnsCount; column++)
      matrix[row][column] = Low + rand() % (High - Low + 1);
}

void Print(
  int** matrix,
  const int rowsCount, const int columnsCount
) {
  cout << endl;
  for (int row = 0; row < rowsCount; row++)
  {
    for (int column = 0; column < columnsCount; column++)
      cout << setw(4) << matrix[row][column];
    cout << endl;
  }
  cout << endl;
}

void RemoveEmpty(
  int** matrix,
  int& rowsCount, int& columnsCount
) {
  RemoveEmptyRows(matrix, rowsCount, columnsCount);
  RemoveEmptyColumns(matrix, rowsCount, columnsCount);
}

void RemoveEmptyRows(
  int** matrix,
  int& rowsCount, const int columnsCount
) {
  for (int row = 0; row < rowsCount; row++)
  {
    bool onlyZero = true;

    for (int column = 0; column < columnsCount; column++) {
      if (matrix[row][column] != 0) {
        onlyZero = false;
      }
    }

    if (onlyZero) {
      DeleteRow(matrix, rowsCount, row);
      row--;
    }
  }
}

void RemoveEmptyColumns(
  int** matrix,
  const int rowsCount, int& columnsCount
) { 
  for (int column = 0; column < columnsCount; column++)
  {
    bool onlyZero = true;

    for (int row = 0; row < rowsCount; row++) {
      if (matrix[row][column] != 0) {
        onlyZero = false;
      }
    }

    if (onlyZero) {
      MoveColumn(matrix, rowsCount, columnsCount, column);
      column--;
    }
  }
}

void DeleteRow(
  int** matrix,
  int& rowsCount, const int rowIndex
) {
  delete[] matrix[rowIndex];

  int** temp = new int* [rowsCount - 1];

  int tempIndex = 0;

  for (int i = 0; i < rowsCount; ++i)
    if (i != rowIndex) 
      temp[tempIndex++] = matrix[i];

  rowsCount = rowsCount - 1;

  for (int i = 0; i < rowsCount; ++i)
    matrix[i] = temp[i];
};

void MoveColumn(
  int** matrix, 
  const int rowCount, int& columnCount,
  const int startIndex
) {
  int temp;

  for (int column = startIndex; column < columnCount - 1; column++)
    for (int j = 0; j < rowCount; j++) {
      temp = matrix[j][column];
      matrix[j][column] = matrix[j][column + 1];
      matrix[j][column + 1] = temp;
    }

  columnCount--;
}

int FindPositiveNumber(int** matrix, const int rowsCount, const int columnsCount)
{
  for (int row = 0; row < rowsCount; row++)
    for (int column = 0; column < columnsCount; column++)
      if (matrix[row][column] > 0)
        return row + 1;

  return -1;
}