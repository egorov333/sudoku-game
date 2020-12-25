#include "Grid_Filling.h"
#include "globals.h"
#include "color.h"
#include <time.h>
#include <iostream>

using namespace std;

bool checkRowGen(unsigned short x, unsigned short y) {
	for (int i = 0; i < y; i++)
		if (sudoku[x][i] == sudoku[x][y])
			return false;
	return true;
}

bool checkColGen(unsigned short x, unsigned short y) {
	for (int i = 0; i < x; i++)
		if (sudoku[i][y] == sudoku[x][y])
			return false;
	return true;
}

bool checkSquareGen(unsigned short x, unsigned short y) {
	unsigned short i_start = x / 3;      i_start *= 3;
	unsigned short j_start = y / 3;      j_start *= 3;

	for (int i = i_start; i < i_start + 3; i++)
		for (int j = j_start; j < j_start + 3; j++) {
			if (i == x && j == y)
				return true;
			if (sudoku[i][j] == sudoku[x][y])
				return false;
		}
	return true;
}

bool test(unsigned short i, unsigned short j) {
	unsigned short current = i * Size + j;

	for (int x = 0; x < Size; x++)
		if (test_array[current][x] == 0)
			return true;
	return false;
}

bool CheckRepeated(unsigned short i, unsigned short j) {
	unsigned short value = sudoku[i][j] - 1;
	unsigned short current = i * Size + j;

	if (test_array[current][value] == 1)
		return true;
	else
		return false;
}

void moveback(int& i, int& j) {
	unsigned short current = i * Size + j;

	for (int x = 0; x < Size; x++)
		test_array[current][x] = 0;

	if (j < 1) {
		i--;
		j = 8;
	}
	else
		j--;
}

void write(unsigned short  i, unsigned short j) {
	unsigned short current = i * Size + j;
	unsigned short value = sudoku[i][j] - 1;
	test_array[current][value] = 1;
}

void print(bool c) {
	unsigned short i_row = 9, j_row = 9;
	unsigned short i_col = 9, j_col = 9;
	unsigned short i_sq = 9, j_sq = 9;
	bool b = true;
	if (!c) {
		i_row = 9, j_row = 9;
		i_col = 9, j_col = 9;
		i_sq = 9, j_sq = 9;
		for (int i = 0; i < Size; i++) {
			for (int j = 0; j < Size; j++) {
				if (sudoku[i][j] != 0 && sudoku[i][j] != genGrid[i][j]) {
					for (int k = 0; k < Size; k++) {
						if (k != j && sudoku[i][j] == genGrid[i][k]) {
							i_row = i; j_row = k;
							break;
						}
					}
					for (int k = 0; k < Size; k++) {
						if (k != i && sudoku[i][j] == genGrid[k][j]) {
							i_col = k; j_col = j;
							break;
						}
					}
					unsigned short i_start = i / 3;      i_start *= 3;
					unsigned short j_start = j / 3;      j_start *= 3;

					for (int k = i_start; k < i_start + 3; k++) {
						if (b) {
							for (int f = j_start; f < j_start + 3; f++) {
								if (k != i && f != j && sudoku[i][j] == genGrid[k][f]) {
									i_sq = k; j_sq = f;
									b = false;
									break;
								}
							}
						}
						else
							break;
					}
				}
			}
		}
	}
	for (int i = 0; i < Size; i++) {
		if (i % 3 == 0)
			cout << "=========================\n";
		cout << "| ";

		for (int j = 0; j < Size; j++) {
			if (sudoku[i][j] != 0 && sudoku[i][j] != genGrid[i][j]) {
				setColor(Red, Black);
				cout << sudoku[i][j] << " ";
				setColor(Green, Black);
			}
			else if (i_row != 9 && i == i_row && j == j_row) {
				setColor(Red, Black);
				cout << sudoku[i][j] << " ";
				setColor(Green, Black);
			}
			else if (i_col != 9 && i == i_col && j == j_col) {
				setColor(Red, Black);
				cout << sudoku[i][j] << " ";
				setColor(Green, Black);
			}
			else if (i_sq != 9 && i == i_sq && j == j_sq) {
				setColor(Red, Black);
				cout << sudoku[i][j] << " ";
				setColor(Green, Black);
			}
			else if (sudoku[i][j] == 0)
				cout << "  ";
			else if (genGrid[i][j] != 0) {
				setColor(Yellow, Black);
				cout << genGrid[i][j] << " ";
				setColor(Green, Black);
			}
			else
				cout << sudoku[i][j] << " ";
			if ((j + 1) % 3 == 0)
				cout << "| ";
		}
		cout << endl;
	}
	cout << "=========================\n";
}

void adjustGrid() {
	unsigned short i = 0, j = 0, k = 0;
	srand(time(0));

	for (k = 0; k < closedElem; k++) {
		while (true) {
			i = rand() % Size;
			j = rand() % Size;
			if (sudoku[i][j] == 0)
				continue;
			sudoku[i][j] = 0;
			break;
		}
	}

	for (i = 0; i < Size; i++) {
		for (j = 0; j < Size; j++)
			genGrid[i][j] = sudoku[i][j];
	}
}

void generator() {
	srand(time(0));
	for (int i = 0; i < Size; i++) {
		for (int j = 0; j < Size; j++) {
			for (;;) {
				if (!test(i, j))
					moveback(i, j);
				sudoku[i][j] = rand() % Size + 1;
				if (CheckRepeated(i, j))
					continue;
				write(i, j);
				if (checkSquareGen(i, j) && checkRowGen(i, j) && checkColGen(i, j))
					break;
			}
		}
	}

	adjustGrid();
	print(true);
}