#pragma once

const int Size = 9;
unsigned short sudoku[Size][Size];
unsigned short test_array[Size*Size][Size] = { 0 };
unsigned short grid[Size][Size] = { 0 };
unsigned short genGrid[Size][Size] = { 0 };
unsigned short closedElem = 0;
int statWin = 0;
int statLose = 0;