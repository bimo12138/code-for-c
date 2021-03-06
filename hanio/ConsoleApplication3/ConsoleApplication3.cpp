#include "pch.h"
#include <iostream>
using namespace std;

void move(int x, int y) {
	printf("%c --> %c \n", x, y);
}

void hanoi(int num, int x, int y, int z) {
	if (num == 0) {
		move(x, z);
	}
	else {
		hanoi(num -1, x, z, y);
		move(x, z);
		hanoi(num - 1, y, x, z);
	}
}


int main()
{
	hanoi(4, 'X', 'Y', 'Z');
	return 1;
}
