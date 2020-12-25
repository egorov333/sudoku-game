#include "menu.h"
#include "color.h"
#include "Grid_Filling.h"
#include "globals.h"
#include <Windows.h>
#include <conio.h>
#include <iostream>

using namespace std;


unsigned short startMenu() {
	unsigned short choice = 0, temp = 0;
	system("cls");
	cout << "1. Info\n2. Game menu\n3. Exit the game\n";
	while (true) {
		temp = _getch();
		if (temp == 8) {
			cout << "\b \b";
			choice = 0;
			continue;
		}
		if ((temp >= 49 && temp <= 51) && choice == 0) {
			choice = temp - 48;
			cout << choice;
			continue;
		}
		if (temp == 13 && choice != 0) {
			system("cls");
			break;
		}
	}
	return choice;
}

void gameInfo() {
	cout << "Hello user!\n This is a classic Sudoku. The rules are simple: fill in all the fields so that there are no duplicate elements in each rows, columns and 3 * 3 sectors. The only solution, you won't get lost. Items that are";
	setColor(Yellow, Black);
	cout << " yellow ";
	setColor(Green, Black);
	cout << "are non-removable. Elements that are";
	setColor(Red, Black);
	cout << " red ";
	setColor(Green, Black);
	cout << "do not fit(either such an element is already in the sector / row / column, or you deviated from the solution)\nGood Luck!\n";
	system("pause");
}

unsigned short gameMenu() {
	unsigned short choice = 0, temp = 0;
	system("cls");
	cout << "1. Start new game\n2. Show statistic\n3. Return to start menu\n";
	while (true) {
		temp = _getch();
		if (temp == 8) {
			cout << "\b \b";
			choice = 0;
			continue;
		}
		if (temp >= 49 && temp <= 51) {
			choice = temp - 48;
			cout << choice;
			continue;
		}
		if (temp == 13 && choice != 0) {
			system("cls");
			break;
		}
	}
	return choice;
}

unsigned short chooseLevel() {
	unsigned short choice = 0, temp = 0;
	cout << "Select difficulty level:\n";
	cout << "1. Very easy\n2. Easy\n3. Medium\n4. Hard\n5. Extreme\n";

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
		if (temp == 13 && choice != 0) {
			system("cls");
			break;
		}
	}
	return choice;
}

void gameStatistic() {
	cout << "Your statistic:\nVictories: ";
	setColor(Magenta, Black);
	cout << statWin;
	setColor(Green, Black);
	cout << "\nLosses: ";
	setColor(Red, Black);
	cout << statLose << endl;
	setColor(Green, Black);
	system("pause");
}

unsigned short chooseFilling() {
	unsigned short choice = 0, temp = 0;
	cout << "How do you want to fill the game grid?\n";
	cout << "1. Manual input\n2. Autocomplete\n";

	while (true) {
		temp = _getch();
		if (temp == 8) {
			cout << "\b \b";
			choice = 0;
			continue;
		}
		if ((temp == 49 || temp == 50) && choice == 0) {
			choice = temp - 48;
			cout << choice;
			continue;
		}
		if (temp == 13 && choice != 0) {
			system("cls");
			break;
		}
	}
	return choice;
}

void beforeGame() {
	unsigned short temp = 0, choice = 0;

	while (true) {
		system("cls");
		generator();
		cout << "1. Start game\n2. Reset game grid\n";
		while (true) {
			temp = _getch();
			if (temp == 8) {
				cout << "\b \b";
				choice = 0;
				continue;
			}
			if ((temp == 49 || temp == 50) && choice == 0) {
				choice = temp - 48;
				cout << choice;
				continue;
			}
			if (temp == 13 && choice != 0)
				break;
		}
		if (choice == 1)
			break;
		else
			choice = 0;
	}
}

unsigned short selectValue() {
	unsigned short temp = 0, val = 0;

	while (true) {
		temp = _getch();
		if (temp == 8) {
			cout << "\b \b";
			val = 0;
			continue;
		}
		if ((temp >= 49 && temp <= 57) && val == 0) {
			val = temp - 48;
			cout << val;
			continue;
		}
		if (temp == 13 && val != 0)
			break;
	}

	return val;
}

unsigned short closedElements() {
	unsigned short temp = 0, val = 0, ten = 0, unit = 0;
	bool b = false;
	cout << "How many open items will there be?\n";

	while (true) {
		temp = _getch();
		if (temp == 8) {
			cout << "\b \b";
			if (ten != 0 && !b) {
				ten = 0;
				continue;
			}
			if (ten != 0 && b) {
				b = false;
				continue;
			}
		}
		if (ten == 0 && temp >= 49 && temp <= 57) {
			ten = temp - 48;
			cout << ten;
			continue;
		}
		if (ten >= 1 && ten <= 7 && !b && temp >= 48 && temp <= 57) {
			unit = temp - 48;
			cout << unit;
			b = true;
			continue;
		}
		if (ten == 8 && !b && (temp == 48 || temp == 49)) {
			unit = temp - 48;
			cout << unit;
			b = true;
			continue;
		}
		if (temp == 13 && ten != 0)
			break;
	}

	if (!b) return ten;
	else {
		val = ten * 10 + unit;
		return val;
	}
}