#include "pch.h"
#include <iostream>
#include <malloc.h>
using namespace std;
typedef struct node {
	char date;
	struct node *lchild, *rchild;
} binnode;

typedef struct stack {
	binnode *data[100];
	int top;
} seqstack;

void push(seqstack *s, binnode *t) {
	/* 把 s 栈里面的data数据的栈顶的元素的值赋值为 t，也就是 head， 栈顶自增1*/
	s->data[s->top] = t;
	s->top++;
 }

binnode *pop(seqstack *s) {
	if (s->top != 0) {
		s->top--;
		return (s->data[s->top]);
	}
	else {
		return NULL;
	}
}

binnode *createbintree() {
	binnode *head;
	int ch;
	if ((ch = getchar()) == '#') {
		return NULL;
	}else {
		head = (binnode *)malloc(sizeof(binnode));
		head->date = ch;
		head->lchild = createbintree();
		head->rchild = createbintree();
	}
	return head;
}

void proorder_1(binnode *head) {
	seqstack s;
	s.top = 0;
	while (head || (s.top != 0)) {
		/* 如果head存在， 根结点存在|| s是存储根节点的栈，知道退到 */
		if (head) {
			/* 输出根节点 */
			cout << head->date;
			/* 把 head 地址赋值给 存储的栈 */
			push(&s, head);
			/* 保存结束后head 为上次head 的左结点*/
			head = head->lchild;
		}
		else {
			/* 如果 head 不存在，即二叉树的左结点不存在 ，即 中 -> 左 -> 右的顺序， 进行遍历 */
			/* pop 是用来返回上一个根节点，便于找到左结点， 然后由原左结点的双亲指引到当前结点的右节点 */
			head = pop(&s);
			head = head->rchild;
		}
	}
}
int main()
{
	binnode *head;
	cout << "开始初始化：";
	head = createbintree();
	cout << "开始前序输出:";
	proorder_1(head);
}
