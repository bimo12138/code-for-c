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


/* 顺序排序的命令 */
linklist *mergeAscend(linklist *h1, linklist *h2) {
	linklist *H1, *H2, *p, *q;
	/* H1 and H2 是一个地址 */
	H1 = H2 = (linklist *)malloc(sizeof(linklist));
	/* p 指向 h1 首结点的后面一个节点 q 指向 h2 首结点后面一个结点 */
	p = h1->next;
	q = h2->next;
	/* p && q 表示两者均存在的， 如果是NULL 那么就会直接跳过 */
	while (p && q) {
		/* 如果 h1 里面的info 小于 h2 的 info 进入 if */
		if (p->info < q->info) {
			/* h1 是前面一个链表， 而且h1在这个判断里面不会改变 */
			/* 如果 p 的info 要和 q 的 info 的位置互换 */
			/* 第一次 
				p -> info === h1 -> next -> info 
				p -> next = h1 -> next -> next
				h1->next = p->next === h1 -> next= h1 -> next -> next 
				H2 是一个零时的存储变量
				最后 p 进入到下一个的 next
 			*/
			h1->next = p->next;
			H2->next = p;
			H2 = p;
			p = h1->next;
		}
		else {
			/**/
			h2->next = q->next;
			H2->next = q;
			H2 = q;
			q = h2->next;
		}
	}
	/* 如果 p进入了h1 或者 h2 的最后一个如果 p 比 q 短那么q会接到最后， 反之亦然 */
	if (p) {
		H2->next = p;
	}
	if (q) {
		H2->next = q;
	}
	free(h1);
	free(h2);
	return H1;
}

/* 倒 */
linklist *mergeDescend(linklist *h1, linklist *h2) {
	linklist  *H1, *p , *q;
	H1 = (linklist *)malloc(sizeof(linklist));
	H1->next = NULL;
	p = h1->next;
	q = h2->next;
	while (p && q) {
		/* p 为 1 q 为 2 p 的 next 是 3 的地址 p 要和 q 换位置， H1 的 next 接 p 的地址*/
		if (p->info < q->info) {
			h1->next = p->next;
			p->next = H1->next;
			H1->next = p;
			p = h1->next;
		}
		else {
			h2->next = q->next;
			q->next = H1->next;
			H1->next = q;
			q = h2->next;
		}
	}
	while (p) {
		h1->next = p->next;
		p->next = H1->next;
		H1->next = p;
		p = h1->next;
	}
	while (q) {
		h2->next = q->next;
		q->next = H1->next;
		H1->next = q;
		q = h2->next;
	}
	free(h1);
	free(h2);
	return H1;
}

int main(int argc, char** argv) {
	linklist *h1, *h2, *h3;
	datatype a[10] = { 1, 3, 5, 7, 9, 11, 13 }, b[10] = { 2, 4, 6, 8, 10, 12, 14 };
	h1 = creatbyqueue(a);
	h2 = creatbyqueue(b);
	display(h1);
	cout << endl;
	display(h2);

	h3 = mergeAscend(h1, h2);
	cout << endl;
	display(h3);
	/*
	h3 = mergeDescend(h1, h2);
	cout << endl;
	display(h3);
	return 0;
	*/
}

