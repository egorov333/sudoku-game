#pragma once

void Game();
void addValue();
void deleteValue();
bool checkRow(unsigned short row, unsigned short val);
bool checkCol(unsigned short col, unsigned short val);
bool checkSquare(unsigned short row, unsigned short col, unsigned short val);
void suggestValue();
void checkPuzzle();