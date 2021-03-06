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

linklist *interSection(linklist *h1, linklist *h2) {
	linklist *head, *r, *p, *q, *s;
	head = r = (linklist *)malloc(sizeof(linklist));
	p = h1->next;
	while (p) {
		q = h2->next;
		while (q && (q->info != p->info)) {
			q = q->next;
		}
		if (q) {
			s = (linklist *)malloc(sizeof(linklist));
			s->info = p->info;
			r->next = s;
			r = s;
		}
		p = p->next;
	}
	r->next = NULL;
	return head;
}


int main(int argc, char** argv) {
	linklist *h1, *h2, *h3;
	datatype a[10] = { 1, 3, 5, 7, 9, 11, 12 }, b[10] = { 2, 4, 6, 8, 10, 12, 14 };
	h1 = creatbyqueue(a);
	h2 = creatbyqueue(b);
	display(h1);
	cout << endl;
	display(h2);
	h3 = interSection(h1, h2);
	cout << endl;
	display(h3);
	return 0;
}


