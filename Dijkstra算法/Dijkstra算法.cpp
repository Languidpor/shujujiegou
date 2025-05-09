#include<stdio.h>
#define M 20
#define N 10
#define MAX 10000

void Dijkstra(int v, int dist[][N], int D[N], int p[N], int s[N]);
int flag[N] = { 0 };
int flag1 = 0;
int flag2 = 0;

typedef struct
{
	int startvex;
	int endvex;
	int length;
} edge; //边的结构体
edge T[M];

void main()
{
	int dist[N][N] = {
		{0,MAX,MAX,MAX,MAX,1,MAX,MAX,MAX,MAX},
		{MAX,0,MAX,MAX,MAX,MAX,1,MAX,MAX,MAX},
		{MAX,MAX,0,MAX,MAX,MAX,MAX,1,MAX,MAX},
		{MAX,MAX,MAX,0,MAX,MAX,MAX,MAX,1,MAX},
		{MAX,MAX,MAX,MAX,0,MAX,MAX,MAX,MAX,1},
		{1,MAX,MAX,MAX,MAX,0,MAX,MAX,MAX,MAX},
		{MAX,1,MAX,MAX,MAX,MAX,0,MAX,MAX,MAX},
		{MAX,MAX,1,MAX,MAX,MAX,MAX,0,MAX,MAX},
		{MAX,MAX,MAX,1,MAX,MAX,MAX,MAX,0,MAX},
		{MAX,MAX,MAX,MAX,1,MAX,MAX,MAX,MAX,0}
	};
	int D[N] = { 0 };
	int p[N] = { 0 };
	int s[N] = { 0 };
	int num = 0;
	Dijkstra(0, dist, D, p, s);
}

void Dijkstra(int v, int dist[][N], int D[N], int p[N], int s[N])
{
	int i, j, k, v1, min, max = 10000, pre;
	v1 = v;
	for (int i = 0; i < N; i++)
	{
		D[i] = dist[v1][i];
		if (D[i] != MAX)
			p[i] = v1 + 1;
		else
			p[i] = 0;
		s[i] = 0;
	}
	s[v1] = 1;
	for (i = 0; i < N - 1; i++)
	{
		min = 10001;
		for(j=0;j<N-1;j++)
			if ((!s[j]) && (D[j] < min))
			{
				min = D[j];
				k = j;
			}
		s[k] = 1;
		for(j=0;j<N;j++)
			if ((!s[j]) && (D[j] > D[k] + dist[k][j]))
			{
				D[j] = D[k] + dist[k][j];
				p[j] = k + 1;
			}
	}
	for (i = 0; i < N; i++)
	{
		printf("%d : %d ", D[i], i);
		pre = p[i];
		while ((pre != 0) && (pre != v + 1))
		{
			printf(" <- %d", pre - 1);
			pre = p[pre - 1];
		}
		printf(" <- %d \n", v);
	}
}