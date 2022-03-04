#pragma once

#ifndef _SUBFUNCTIONS_H_
#define _SUBFUNCTIONS_H_
#include <iostream>
#include <iomanip>

#pragma region Auto_Fill
void AutoFillMatrix(
  int** matrix,
  const int rowsCount, const int columnsCount,
  const int Low, const int High,
  const int currentRow = 0
);

void AutoFillMatrixRow(
  int** matrix,
  const int columnsCount,
  const int Low, const int High,
  const int currentRow, const int currentColumn = 0
);

#pragma endregion Auto_Fill

#pragma region Manual_Fill
void ManualFillMatrix(
  int** matrix,
  const int rowsCount, const int columnsCount,
  const int currentRow = 0
);

void ManualFillMatrixRow(
  int** matrix,
  const int columnsCount,
  const int currentRow, const int currentColumn = 0
);
#pragma endregion Manual_Fill

#pragma region Print
void Print(
  int** matrix,
  const int rowsCount, const int columnsCount,
  const int currentRow = 0
);

void PrintRow(
  int** matrix,
  const int columnsCount,
  const int currentRow, const int currentColumn = 0
);
#pragma endregion Print

#endif // !_SUBFUNCTIONS_H_
