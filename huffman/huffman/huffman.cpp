#include "pch.h"
#include <iostream>
#include <malloc.h>
using namespace std;
typedef struct node {
	int data;
	struct node *lchild, *rchild, *next;
} hufnode;

hufnode *insert(hufnode *head, hufnode *s) {
	hufnode *p1, *p2;
	if (head == NULL) {
		head = s;
	}
	else {
		p1 = NULL;
		p2 = head;
		/* 如果 head 存在， 并且 head 的 data 比 s 也就是要插入的值要小 */
		/* while 循环最后得到的是 整个二叉树以及被插入的值中所有的最小两个值， 最后p2要么为NULL， 要么就是比 s 的 data 大的 */
		while (p2 && p2->data < s->data) {
			/* p 初始为 NULL ，p2 是head */ 
			p1 = p2;
			/* p2 成为了 p2 的后继结点 */
			p2 = p2->next;
		}
		/* s 是需要插入的二叉树 s2 -> next = p2 表示 s2 的后继结点变成了经过 while 循环取得的最小的两个值中较大的一个 */
		s->next = p2;
		/* p1 为NULL 条件是 p1 没有走过 while 循环，也就是 p2 的数据端口比 s 的要大 */
		if (p1 == NULL) {
			head = s;
		}
		/* else 表示 p1 是有数据的， 那么 p1 的后继为 s ，s 的后继是 p2， 也就是变成了 p1 -> s -> p2 */
		else {
			p1->next = s;
		}
	}
	return head;
}

hufnode *creathuffman(hufnode *head) {
	hufnode *s, *r1, *rr;
	/* head 和 head 的后继都是存在的 */
	while (head && head->next) {
		/* r1 rr 来替换 head 和 head 的后继 */
		r1 = head;
		rr = head->next;
		/* head 赋值为 rr 的后继 也就是 head 的后继的后继 */
		head = rr->next;
		/* s 是临时存储的 */
		s = (hufnode *)malloc(sizeof(hufnode));
		s->next = NULL;
		/* s的数据接口是 r1 和 r2 的和， 也就是 head 和 head 的 next 的数据的和 */
		s->data = r1->data + rr->data;
		/* s 左结点为 head 右节点为 head ->next */
		s->lchild = r1;
		s->rchild = rr;
		/* head 和 head -> next 的 next 均为 NULL */
		r1->next = rr->next = NULL;
		head = insert(head, s);
	}
	return head;
}

void preorder(hufnode *head) {
	if (head) {
		cout << head->data << "  ";
		preorder(head->lchild);
		preorder(head->rchild);
	}
}

int main()
{
	hufnode *head = NULL, *s;
	int ch;
	/* 输入的数值是按从小到大排序好的 */
	scanf_s("%d", &ch);
	while (ch != 0) {
		/* s 作为一个临时存储的二叉树般的存在 s 的指针域都是为 NULL 的*/
		s = (hufnode *)malloc(sizeof(hufnode));
		s->data = ch;
		s->next = NULL;
		s->lchild = s->rchild = NULL;
		/* 插入操作 */
		head = insert(head, s);
		scanf_s("%d", &ch);
	}
	cout << endl;
	head = creathuffman(head);
	preorder(head);
}