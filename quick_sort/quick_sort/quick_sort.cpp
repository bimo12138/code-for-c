#include "pch.h"
#include <iostream>
using namespace std;

void quick_sort(int a[], int left, int right) {
	int i, j, temp;
	if (left < right) {
		i = left;
		j = right;
		/* temp 是用来存储要被替代的数的位置的数据 */
		temp = a[i];
		/* 循环 */
		do {
			/* 前面一部分的 while if 是用来找到比 a[i] 小的数据，并且把那么把 a[j] 替换到 a[i] 的位置 ， 然后是 left 为 i + 1*/
			while (a[j] > a[i] && i < j) {
				j--;
			}
			if (i < j) {
				a[i] = a[j];
				i++;
			}
			/* 然后找出比 temp 大的数据， 并且用从后往前存的方法来存储 */
			while (a[i] < temp && i < j) {
				i++;
			}
			if (i < j) {
				a[j] = a[i];
				j--;
			}
		} while (i != j);
		/* 最后把重合的那部分的下标， 赋值为 temp */
		a[i] = temp;
		/* 双向递归 */
		quick_sort(a, left, i - 1);
		quick_sort(a, i + 1, right);
	}
}

void display(int a[]) {
	int i;
	for (i = 0; i < 10; i++) {
		cout << a[i] << " ";
	}
}
int main()
{
	int a[10] = {7,6,9,8,5,2,1,4,3,0};
	quick_sort(a, 0, 9);
	display(a);
}

