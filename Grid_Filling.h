#pragma once

bool checkRowGen(unsigned short x, unsigned short y);
bool checkColGen(unsigned short x, unsigned short y);
bool checkSquareGen(unsigned short x, unsigned short y);
bool test(unsigned short i, unsigned short j);
bool CheckRepeated(unsigned short i, unsigned short j);
void moveback(int& i, int& j);
void write(unsigned short i, unsigned short j);
void print(bool c);
void adjustGrid();
void generator();