#define TRUE 1
#define MAX_VERTICES 100
#define INF 1000L
#include <stdio.h>
#include <stdlib.h>



typedef struct GraphType {
	int n;
	int weight[MAX_VERTICES][MAX_VERTICES];

}GraphType;

int selected[MAX_VERTICES];
int distance[MAX_VERTICES];

int get_min_vertex(int n) {

	int v, i;
	for (i = 0; i < n; i++) {

		if (!selected[i]) {
			v = i;
			break;
		}


	}
	for (i = 0; i < n; i++) {
		if (!selected[i] && (distance[i] < distance[v])) v = i;

	}

	return (v);


}

void prim(GraphType* g, int s, GraphType* g_mst) {
	int i, u, v;

	for (u = 0; u < g->n; u++) {
		distance[u] = INF;
	}
	distance[s] = 0;
	for (i = 0; i < g->n; i++) {
		u = get_min_vertex(g->n);
		selected[u] = TRUE;
		if (distance[u] == INF)return;

		printf("정점 %d 추가 \n", u);

		for (v = 0; v < g->n; v++) {
			if (g->weight[u][v] != INF) {
				if (!selected[v] && g->weight[u][v] < distance[v]) {
					distance[v] = g->weight[u][v];
					g_mst->weight[u][v] = 1;

					for (int j = 0; j < g->n; j++) g_mst->weight[j][v] = INF;

					g_mst->weight[u][v] = 1;
				}
			}
		}

	}

}

int main(void) {
	GraphType g = { 7,{{0,29,INF,INF,INF,10,INF},
		{29,0,16,INF,INF,INF,15},
		{INF,16,0,12,INF,INF,INF},
		{INF,INF,12,0,22,INF,18},
		{INF,INF,INF,22,0,27,25},
		{10,INF,INF,INF,27,0,INF},
		{INF,15,INF,18,25,INF,0}} };

	GraphType g_mst = { 7,{{INF,INF,INF,INF,INF,INF,INF},
		{INF,INF,INF,INF,INF,INF,INF},
		{INF,INF,INF,INF,INF,INF,INF},
		{INF,INF,INF,INF,INF,INF,INF},
		{INF,INF,INF,INF,INF,INF,INF},
		{INF,INF,INF,INF,INF,INF,INF},
		{INF,INF,INF,INF,INF,INF,INF}} };


	prim(&g, 0, &g_mst);

	for (int i = 0; i < 7; i++) {
		g_mst.weight[i][i] = 0;
		for (int j = 0; j < 6; j++) {
			printf("%d\t\t", g_mst.weight[i][j]);
		}
		printf("\n");
	}
	return 0;

}

