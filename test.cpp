#include "color.h"
#include "globals.h"
#include "Grid_Filling.h"
#include "menu.h"
#include "Game.h"
#include <iostream>

using namespace std;


int main() {
	setColor(Green, Black);
	unsigned short choice = 0, level = 0, filling = 0, temp = 0;
	bool b = false;

	while (true) {
		choice = startMenu();

		if (choice == 1) {
			gameInfo();
			continue;
		}
		if (choice == 3) {
			cout << "Bye!\n";
			return 0;
		}
		if (choice == 2) {
			while (true) {
				choice = gameMenu();

				if (choice == 2) {
					gameStatistic();
					continue;
				}
				if (choice == 3) {
					break;
				}
				if (choice == 1) {
					filling = chooseFilling();

					if (filling == 1) {
						closedElem = 81 - closedElements();
						generator();
						Game();
					}
					else {
						level = chooseLevel();
						closedElem = 18 + 9 * level;
						beforeGame();
						Game();
					}
				}
			}
		}
	}

	return 0;
}