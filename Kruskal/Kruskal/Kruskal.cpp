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

/* 这个是每条边的信息，保存最小生成树的边的 length */
typedef struct edgedata {
	/* beg 为开始的顶点的标识， en 为结尾的顶点的表示 */
	int beg, en;
	/* 这条边的权值 */
	int length;
} edge;

/* 快速排序算法， left 和 right 分别代表他们的左右下标 */
void quick_sort(edge edges[], int left, int right) {
	
	edge x;
	int i, j, flag = 1;
	if (left < right) {
		
		i = left;
		j = right;
		/* x代表需要排序的数组的第 i（leftr）位 */
		x = edges[i];
		/* left 要比 right 下标小 */
		while (i < j) {
			/* x.length 是第一个的权值，从后往前遍历比 edges 的 j 、小的位置 */
			while (i < j && x.length < edges[j].length) {
				j--;
			}
			/* 如果程序是遍历到了比第一个的权值小的 */
			if (i < j) {
				/* 就把比那个比第一个小的赋值给第一个 */
				edges[i++] = edges[j];
			}
			/* 然后找比第一个的权值小的 */
			while(i < j && x.length > edges[i].length) {
				i++;
			}
			if (i < j) {
				/* 把比第一个值大的，赋值给最右边开始的数*/
				edges[j--] = edges[i];
			}
		}
		/* 最后把第一个数赋值给中间的 i */
		edges[i] = x;
		/* 左边一半进行递归 */
		quick_sort(edges, left, i - 1);
		/* 右边 */
		quick_sort(edges, i + 1, right);
	}
}

/* 读取边的数据 */
void get_edge(Margh g, edge edges[]) {
	int i, j, k = 0;
	/* 循环所有的边数 */
	for (i = 0; i < g.n; i++) {
		/* 0， 1， 2， 3 次循环*/
		for (j = 0; j < i; j++) {
			/* 如果 g 的矩阵的数据为 0 或者不是 1000 （就是有数据的）*/
			if (g.edges[i][j] != 0 && g.edges[i][j] < 1000) {
				edges[k].beg = i;
				edges[k].en = j;
				/* k 在 edges 进行赋值后， 自增， 并且把权值赋值 */
				edges[k++].length = g.edges[i][j];
			}
		}
	}
}

void kruskal(Margh g) {
	int i, j, k = 0, ltfl;
	int cnvx[20];
	/* 存储所有的边的数据 400 是为了防止所有的边的数目，导致数据超出数组的最大容量 */
	edge edges[400];
	/* 存放最小生成树的边的数据 */
	edge tree[20];
	/* 读取每个顶点的所有边的数据 */
	get_edge(g, edges);
	/* 对边进行快速排序 */
	quick_sort(edges, 0, g.e - 1);
	/* 把几个边数，全都赋值给 cnvx */
	for (i = 0; i < g.n; i++) {
		cnvx[i] = i;
	}

	for (i = 0; i < g.n - 1; i++) {
		/* 当 k 的开始和结束节点相同的时候 ， pass */
		/* 目的： 去除数组里面的自己指向自己的边 */
		while (cnvx[edges[k].beg] == cnvx[edges[k].en]) {
			k++;
		}
		/* 把排序后的第一个{最小的} 存储到 tree 的0级 */
		tree[i] = edges[k];
		/* ltfl 用来存储 边的结束的节点 */
		ltfl = cnvx[edges[k].en];
		/* 每条边循环一次 */
		for (j = 0; j < g.n; j++) {
			/* ltfl 是 cnvx 的 边的末节点 cnvx 是循环遍历的吗所以如果这个节点有做过末节点 ， 那么它将被边的首节点覆盖 */
			if (cnvx[j] == ltfl) {
				cnvx[j] = cnvx[edges[k].beg];
			}
		}
		/* k 是当前边的序号 */
		k++;
	}
	cout << "最小生成树为：" << endl;
	for (j = 0; j < g.n - 1; j++) {
		cout << g.info[tree[j].beg] << " ---> " << g.info[tree[j].en] << "  " << tree[j].length << endl;
	}
}
void create(Margh *g, char *s, int c) {
	int i, j, k, w;
	i = 0;
	FILE *rf;
	rf = fopen(s, "r");
	if (rf) {
		/* 读取文件第一行格式为 %d 和 %d 中间以一个或者若干个空格 分开 */
		fscanf(rf, "%d%d", &g->n, &g->e);
		/* 读取第二行的数据， 用 %s 的类型读取，每次读取一个， 后面会自动到info[1], info[2], …… */
		fscanf(rf, "%s", &g->info[i]);
		/* 初始化 INIT */
		/* 如果 i = j 则赋值为0， 表示这个自身到自身的关系是并不存在的，如果不是自身的，则赋值一个代表无穷大的数，表示这个数是存在的，并且在最后得出结果后，为 1000 则代表没有这个线 */
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
		/* 读取具体的边的数据，把图的数据丰富好 */
		for (k = 0; k < g->e; k++) {
			/*读取起点， 终点， 权值 分别对应 i, j, w */
			fscanf(rf, "%d%d%d", &i, &j, &w);
			/* i， j 代表起点和终点最后 g 的 edges ，并且是赋值为权值 */
			g->edges[i][j] = w;
			/* 如果是无向图，就把 j， i也要赋值， 达成 i，j 和j， i 都是这个边 */
			if (c == 0) {
				g->edges[j][i] = w;
			}
		}
		/* 关闭文件的占用指针 */
		fclose(rf);
	}
	/* 如果文件指针不存在， 则把g的定点数赋值为0， 防止出现任何问题 */
	else {
		g->n = 0;
	}
}

int main()
{
	Margh g;
	char filename[20];
	cout << "请输入数据：" << endl;
	cin >> filename;
	create(&g, filename, 0);
	kruskal(g);
	return 0;
}