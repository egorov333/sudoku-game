#include "Game.h"
#include "globals.h"
#include "Grid_Filling.h"
#include "menu.h"
#include <Windows.h>
#include <conio.h>
#include <iostream>

using namespace std;


void Game() {
	unsigned short choice = 0, temp = 0;

	while (true) {
		if (closedElem != 0) {
			system("cls");
			print(true);

			cout << "1. Enter number\n2. Remove number\n3. Suggest the number\n4. Finish the game\n5. Check if sudoku can be solved\n";
			while (true) {
				temp = _getch();
				if (temp == 8) {
					cout << "\b \b";
					choice = 0;
					continue;
				}
				if ((temp >= 49 && temp <= 53) && choice == 0) {
					choice = temp - 48;
					cout << choice;
					continue;
				}
				if (temp == 13 && choice != 0)
					break;
			}

			if (choice == 1) {
				addValue();
				choice = 0;
				continue;
			}
			if (choice == 2) {
				deleteValue();
				choice = 0;
				continue;
			}
			if (choice == 3) {
				suggestValue();
				choice = 0;
				continue;
			}
			if (choice == 4) {
				unsigned short hlp = 0;
				cout << "\nAre you sure?\n";
				cout << "1. Yes\n2. No\n";

				while (true) {
					temp = _getch();
					if (temp == 8) {
						cout << "\b \b";
						hlp = 0;
						continue;
					}
					if ((temp == 49 || temp == 50) && hlp == 0) {
						hlp = temp - 48;
						cout << hlp;
						continue;
					}
					if (temp == 13 && hlp != 0) break;
				}

				if (hlp == 1) {
					statLose++;
					break;
				}
				else
					continue;
			}
			if (choice == 5) {
				checkPuzzle();
			}
		}
		else {
			system("cls");
			cout << "WIN!\n";
			statWin++;
			system("pause");
			break;
		}
	}
}

void addValue() {
	unsigned short val = 0, col = 0, row = 0, temp = 0;

	cout << "\nSelect row:\n";
	row = selectValue() - 1;

	cout << "\nSelect column:\n";
	col = selectValue() - 1;

	cout << "\nEnter value:\n";
	val = selectValue();

	if (checkRow(row, val) && checkCol(col, val) && checkSquare(row, col, val)) {
		sudoku[row][col] = val;
		closedElem--;
	}
	else {
		temp = sudoku[row][col];
		sudoku[row][col] = val;
		system("cls");
		print(false);
		cout << "You cannot enter this number here!\n";
		system("pause");
		sudoku[row][col] = temp;
	}
}

void deleteValue() {
	unsigned short col = 0, row = 0;

	cout << "\nSelect row:\n";
	row = selectValue() - 1;

	cout << "\nSelect column:\n";
	col = selectValue() - 1;

	if (genGrid[row][col] != 0) {
		cout << "\nYou can't delete this element\n";
		system("pause");
	}
	else {
		sudoku[row][col] = 0;
		closedElem++;
	}
}

void suggestValue() {
	for (int i = 0; i < Size; i++) {
		for (int j = 0; j < Size; j++) {
			if (sudoku[i][j] == 0) {
				sudoku[i][j] = grid[i][j];
				closedElem--;
				return;
			}
		}
	}
}

bool checkRow(unsigned short row, unsigned short val) {
	for (int i = 0; i < Size; i++)
		if (sudoku[row][i] == val)
			return false;
	return true;
}

bool checkCol(unsigned short col, unsigned short val) {
	for (int i = 0; i < Size; i++)
		if (sudoku[i][col] == val)
			return false;
	return true;
}

bool checkSquare(unsigned short row, unsigned short col, unsigned short val) {
	int i_start = row / 3;      i_start *= 3;
	int j_start = col / 3;      j_start *= 3;

	for (int i = i_start; i < i_start + 3; i++)
		for (int j = j_start; j < j_start + 3; j++)
			if (sudoku[i][j] == val)
				return false;
	return true;
}

void checkPuzzle() {
	for (int i = 0; i < Size; i++) {
		for (int j = 0; j < Size; j++) {
			if (sudoku[i][j] != 0 && sudoku[i][j] != grid[i][j]) {
				cout << "\nSudoku cannot be solved\n";
				system("pause");
				return;
			}
		}
	}
	cout << "\nSudoku can be solves\n";
	system("pause");
}