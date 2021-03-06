#include "pch.h"
#include <iostream>
#pragma warning(disable:4996);
using namespace std;

typedef struct {
	/* 信息存储的位置 */
	char info[20];
	/* 各个边的权重，这个二维数组就是临界矩阵 */
	int edges[20][20];
	/* n 代表这个图的顶点总数， e代表边的总数 */
	int n, e;
} Margh;
/* 保存最小生成树的边的 length */
typedef struct edgedata {
	int beg, en;
	int length;
 } edge;


void prim(Margh g, edge tree[19]) {
	edge x;
	int d, min, j, k, s, v;
	for (v = 1; v <= g.n - 1; v++) {
		tree[v - 1].beg = 0;
		tree[v - 1].en = v;
		tree[v - 1].length = g.edges[0][v];
	}
	for (k = 0; k <= g.n - 3; k++) {
		min = tree[k].length;
		s = k;
		for (j = k + 1; j <= g.n - 2; j++) {
			if (tree[j].length < min) {
				min = tree[j].length;
				s = j;
			}
		}
		v = tree[s].en;
		x = tree[s];
		tree[s] = tree[k];
		tree[k] = x;
		for (j = k + 1; j <= g.n - 2; j++) {
			d = g.edges[v][tree[j].en];
			if (d < tree[j].length) {
				tree[j].length = d;
				tree[j].beg = v;
			}
		}
	}
	cout << "\n最小生成树为：\n";
	for (j = 0; j <= g.n - 2; j++) {
		cout << endl << g.info[tree[j].beg] << " ---> " << g.info[tree[j].en] << "   " << tree[j].length;
	}
	cout << endl << "树的起点为：" << g.info[0] << endl;
}

void create(Margh *g, char *s, int c) {
	int i, j, k, w;
	i = 0;
	FILE *rf;
	rf = fopen(s, "r");
	if (rf) {
		fscanf(rf, "%d%d", &g->n, &g->e);
		fscanf(rf, "%s", &g->info[i]);
		for (i = 0; i < g->n; i++) {
			for (j = 0; j < g->n; j++) {
				if (i == j) {
					g->edges[i][j] = 0;
				}
				else {
					g->edges[i][j] = 1000;
				}
			}
		}
		for (k = 0; k < g->e; k++) {
			fscanf(rf, "%d%d%d", &i, &j, &w);
			g->edges[i][j] = w;
			if (c == 0) {
				g->edges[j][i] = w;
			}
		}
		fclose(rf);
	}
	else {
		g->n = 0;
	}
}

int main()
{
	Margh g;
	edge tree[19];
	char filename[20];
	cout << "请输入数据：" << endl;
	cin >> filename;
	create(&g, filename, 0);
	prim(g, tree);
	return 0;
}