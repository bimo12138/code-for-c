#include "pch.h"
#include <iostream>
using namespace std;

typedef char datatype;
typedef struct node {
	datatype data;
	struct node *lchild, *rchild;
} bintnode;

typedef bintnode *bintree;

bintree createbintree() {
	char ch;
	bintree t;
	if ((ch = getchar()) == '#') {
		t = NULL;
	}
	else {
		t = (bintnode *)malloc(sizeof(bintnode));
		t->data = ch;
		t->lchild = createbintree();
		t->rchild = createbintree();
	}
	return t;
}

void preorder(bintree t) {
	if (t) {
		cout << t->data;
		preorder(t->lchild);
		preorder(t->rchild);
	}
}

void inorder(bintree t) {
	if (t) {
		inorder(t->lchild);
		cout << t->data;
		inorder(t->rchild);
	}
}

void postorder(bintree t) {
	if (t) {
		postorder(t->lchild);
		postorder(t->rchild);
		cout << t->data;
	}
}
int main()
{
	/* 示范输入： 378##9##6#5## */
	bintree root;
	root = createbintree();
	preorder(root);
	cout << endl;
	inorder(root);
	cout << endl;
	postorder(root);
	return 0;
}

