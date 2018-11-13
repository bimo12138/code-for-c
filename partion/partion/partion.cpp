#include "pch.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
#define N 10
void input(int a[], int n) {
	int i;
	cout << "请输入整数：\n";
	for (i = 0; i < n; i++) {
		cin >> a[i];
	}
}

void print(int a[], int n) {
	int i;
	cout << "\n数组的内容是：\n:";
	for (i = 0; i < n; i++) {
		if (i % 10 == 0) {
			cout << endl;
		}
		cout << a[i] << " ";
	}
	cout << endl;
}

void init(int a[], int n) {
	int i;
	srand(time(NULL));
	for (i = 0; i < n; i++) {
		a[i] = rand() % 1000;
	}
}
void partion(int a[], int left, int right)
{
	int temp;
	if (left < right) {
		partion(a, left + 1, right - 1);
		temp = a[left];
		a[left] = a[right];
		a[right] = temp;
	}
}
int main()
{
	int a[N];
	init(a, N);
	print(a, N);
	partion(a, 0, N - 1);
	print(a, N);
	return 0;
}
