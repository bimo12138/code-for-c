#include "pch.h"
#include <iostream>


int Ack(int m, int n) {
	if (m == 0) {
		return (n + 1);
	}
	else if (n == 0) {
		return (Ack(m - 1, 1));
	}
	else {
		return (Ack(m - 1, Ack(m, n - 1)));
	}
}
int main()
{
    std::cout << Ack(10, 6); 
	return 0;
}
