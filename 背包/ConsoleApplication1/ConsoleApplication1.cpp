#include "pch.h"
#include <iostream>
#include <stdio.h>
#define MAXSIZE 50
int w[MAXSIZE] = { 0, 1, 2, 3, 4, 5, 6, 7 };

int knapsackl(int s, int m) {
	int s1, b;
	if (s == 0) {
		return 1;
	}
	else if ((s < w[1]) || (m == 0)) {
		return 0;
	}
	else {
		do {
			s1 = w[m];
			m--;
			b = knapsackl(s - s1, m);
		} while ((m != 0) && (!b));
		if (!b) {
			return 0;
		}
		else {
			printf("%d  ", s1);
			return 1;
		}
	}
}

int main() {
	knapsackl(10, 7);
}