#include "pch.h"
#include <iostream>
#include <malloc.h>
#define MAXSIZE 100
using namespace std;

typedef struct node {
	int data;
	struct node *next;
} linknode;

int get_length(char *s) {
	char *q;
	q = s;
	int x;
	x = 0;
	while (*q != '\0') {
		x++;
		q++;
	}
	return x;
}
int index(char *s, char *t) {
	int len_s, len_t;
	int i = 0, j;
	// 获得 s 和 t 的长度的函数
	len_s = get_length(s);
	len_t = get_length(t);
	if (len_t > len_s) {
		// -1 表示 需要匹配的字符 的长度小于，匹配的字符长度。
		return -1;
	}
	while (i <= len_s) {
		j = 0;
		if (*(s + i) == *(t + j)) {
			j++;
			while (j < len_t && *(s + i + j) == *(t + j)) {
				j++;
			}
			// 如果 j 个数字和需要匹配的数字的长度是一样的， 那么 匹配成功
			if (j == len_t) {
				return i;
			}
		}
		// 如果进入这里， 表明这个字符并没有匹配成功， 可以进入下一个字符进行匹配， 而且因为里面是使用 + 并没有赋值， 所以i 是没有改变的，所以仍可以使用。
		i++;
	}
	// -2 表示匹配失败， 没有类似的字符形式
	return -2;
}
/*
int *index_2(char *s, char *t) {
	int len_s, len_t, index_main[MAXSIZE], H = 0, *p;
	int i = 0, j;
	p = index_main;
	// 获得 s 和 t 的长度的函数
	len_s = get_length(s);
	len_t = get_length(t);
	if (len_t > len_s) {
		// -1 表示 需要匹配的字符 的长度小于，匹配的字符长度。
		return index_main;
	}
	while (i <= len_s) {
		j = 0;
		if (*(s + i) == *(t + j)) {
			j++;
			while (j < len_t && *(s + i + j) == *(t + j)) {
				j++;
			}
			// 如果 j 个数字和需要匹配的数字的长度是一样的， 那么 匹配成功
			if (j == len_t) {
				index_main[H] = i;
				H++;
			}
		}
		// 如果进入这里， 表明这个字符并没有匹配成功， 可以进入下一个字符进行匹配， 而且因为里面是使用 + 并没有赋值， 所以i 是没有改变的，所以仍可以使用。
		i++;
	}
	// -2 表示匹配失败， 没有类似的字符形式
		return p;
}
*/
linknode *init() {
	linknode *head;
	head = (linknode *)malloc(sizeof(linknode));
	head->next = NULL;
	return head;
}
linknode *insert(linknode *head, int n) {
	linknode *p;
	p = (linknode *)malloc(sizeof(linknode));
	p->data = n;
	p->next = head->next;
	head->next = p;
	return head;
}
linknode *indexxall(char *s, char *t) {
	int len_s, len_t, p = 0;
	int i = 0, j;
	linknode *head;
	head = (linknode *)malloc(sizeof(linknode));
	// 获得 s 和 t 的长度的函数
	len_s = get_length(s);
	len_t = get_length(t);
	while (i <= len_s) {
		j = 0;
		if (*(s + i) == *(t + j)) {
			j++;
			while (j < len_t && *(s + i + j) == *(t + j)) {
				j++;
			}
			// 如果 j 个数字和需要匹配的数字的长度是一样的， 那么 匹配成功
			if (j == len_t) {
				head = insert(head, i);
			}
		}
		// 如果进入这里， 表明这个字符并没有匹配成功， 可以进入下一个字符进行匹配， 而且因为里面是使用 + 并没有赋值， 所以i 是没有改变的，所以仍可以使用。
		i++;
	}
	return head;
}


void print(linknode *head) {
	linknode *p;
	p = head->next;
	while (p) {
		printf("%5d", p->data);
		p = p->next;
	}
	cout << endl;
}

int main() {
	char s[80], t[80];
	linknode *head;
	cout << "请输入主串：\n";
	gets_s(s);
	cout << "请输入模式串：\n";
	gets_s(t);
	int k = index(s, t);
	cout << "出现这个字符串的其实坐标是：（0为开始位置）" << k;
	head = indexxall(s, t);
	cout << endl;
	print(head);
	return 0;
}


