#include "pch.h"
#include <iostream>

float average(int a[]) {
	int i = 0, sum = 0;
	while (a[i] != '\0') {
		sum += a[i];
		i++;
	}
	return (sum / (i + 1));
}

void display(int ave, int a[]) {
	int i = 0;
	while (a[i] != '\0') {
		if (a[i] > ave) {
			printf("%d  ", a[i]);
		}
		i++;
	}
}
int main()
{
	int a[11] = { 7, 6, 5, 4, 2, 12, 35, 12, 14, 25 }, i = 0;
	float ave;
	while (a[i] != '\0') {
		scanf_s("%d", &a[i]);
		i++;
	}
	ave = average(a);
	printf("平均值为:\n %f \n", ave);
	display(ave, a);
	return 0;
}