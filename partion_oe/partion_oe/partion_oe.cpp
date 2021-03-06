#include "pch.h"
#include <iostream>
#include <malloc.h>
#include<stdlib.h>
using namespace std;

typedef int  datatype;
typedef struct node {
	datatype info;
	struct node *next;
} linklist;
/* 初始化 */
linklist *init() {
	linklist *head;
	head = (linklist *)malloc(sizeof(linklist));
	head->next = NULL;
	return head;
}
/* 显示单链表 */
void display(linklist *head) {
	linklist *p;
	p = head->next;
	if (!p) {
		cout << "这个单链表是空的！";
	}
	else {
		while (p) {
			cout << p->info << " ";
			p = p->next;
		}
	}
}

linklist *creatbyqueue(datatype a[]) {
	int n = 0;
	linklist *head, *q, *s;
	head = init();
	q = head;
	while (a[n] != '\0') {
		s = (linklist *)malloc(sizeof(linklist));
		s->info = a[n];
		q->next = s;
		q = s;
		n++;
	}
	if (q) {
		q->next = NULL;
	}
	return head;
}

int main()
{
	linklist head;
	head = creatbyqueue();
	print(head);
	partion(head);
	print(head);
	delList(head);
	return 0;
}

