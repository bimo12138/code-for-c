#include "pch.h"
#include <iostream>

int main()
{
	int a, b, k, temp_a, temp_b;
	a = 4;
	b = 6;
	if (a < b) {
		for (k = a; k < a * b + 1; k++) {
			temp_a = k % a;
			temp_b = k % b;
			if(temp_a == 0 && temp_b == 0) {
				printf("%d", k);
				return 0;
			}
		}
	}
	else {
		for (k = b; k < a * b; k++) {
			temp_a = k % a;
			temp_b = k % b;
			if (temp_a == 0.0 && temp_b == 0.0) {
				printf("%d", k);
				return 0;
			}
		}
	}
}
