#include "pch.h"
#include <iostream>
#define maxsize 100
using namespace std;
typedef struct {
	char str[maxsize];
	int length;
} seqstring;

void getnext(seqstring p, int next[])
{
	int i, j;
	next[0] = -1;
	i = 0;
	j = -1;
	/* p 的长度为结束的标志， j为-1 是为了保证函数在第一步的时候可以进行下去*/
	while (i < p.length) {
		/* 第一步时候为*/
		if (j == -1 || p.str[i] == p.str[j]) {
			i++;
			j++;
			/* 第一步时， next[1] = 0， i 为 1， j为 0 */
			next[i] = j;
		}
		else {
			j = next[j];
		}
	}
	for (i = 0; i < p.length; i++) {
		printf("%d ", next[i]);
	}
}

int kmp(seqstring t, seqstring p, int next[])
{
	int i, j;
	i = 0;
	j = 0;
	while (i < t.length && j < p.length) {
		if (j == -1 || t.str[i] == p.str[j]) {
			i++;
			j++;
		}
		else {
			j = next[j];
		}
	}
	if (j == p.length) {
		return i - p.length;
	}
	else {
		return -1;
	}
}
int  main()
{
	seqstring t, p;
	int next[maxsize], pos;
	printf("请输入主串：\n");
	gets_s(t.str);
	t.length = strlen(t.str);
	printf("请输入副串：\n");
	gets_s(p.str);
	p.length = strlen(p.str);
	getnext(t, next);
	pos = kmp(t, p, next);
	printf("\n");
	printf("%d", pos);
	return 0;
}

