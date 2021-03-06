#include "pch.h"
#include <iostream>
#include <time.h>
#define N 10
using namespace std;
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

void bubbleSort(int a[], int n)
{
	int i, j, temp;
	i = 0;
	while (n > 0) {
		while (a[i] < a[i ++]) {
			i++;
			j++;
		}
		if (a[i] > a[j]) {
			temp = a[i];
			a[i] = a[j];
			a[j] = temp;
		}
		return bubbleSort(a, n - 1);
	}
}
int binSearch(int a[], int left, int right, int key)
{
	return 1;
}
int main()
{
	int x, pos, a[N];
	init(a, N);
	bubbleSort(a, N);
	print(a, N);
	printf("请输入要查找的数：\n");
	cin >> x;
	pos = binSearch(a, 0, N - 1, x);
	cout << pos;
	/*
	if (pos != -1) printf("a[%d]=%d\n", pos, x);
	else printf("Not found!\n");
	*/
	return 0;
}
