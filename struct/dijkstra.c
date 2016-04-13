/**
 * @file dijkstra.c
 * @brief D算法
 * @author cui
 * @version 1.0
 * @date 2016-04-13
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 150
#define INF (~(1<<31))

/**
 * @name 结构体
 * @{ */
/**  @} */
typedef struct _graph
{
	char vexs[MAX];
	int vexnum;
	int edgnum;
	int matrix[MAX][MAX];
}Graph;

/**
 * @brief 初始化结构体
 *
 * @return 
 */
static Graph create_example_graph()
{
	char vexs[8] = {'A','B','C','D','E','F','G'};
	int matrix[][8] = {
		{0, 12, INF, INF, INF, 16, 14},
		{12, 0,  10, INF, INF,  7, INF},
		{INF,10,  0,   3,   5,  6, INF},
		{INF,INF, 3,   0,   4,  INF,INF},
		{INF,INF, 5,   4,   0,  2,   8},
		{16, 7,   6,   INF, 2,  0,   9},
		{14, INF, INF, INF, 8,  9,   0},
	};
	int i, j;
	Graph pG;
	for(i=0; i<8; i++)
	{
		pG.vexs[i] = vexs[i];
	}
	pG.vexnum = strlen(vexs);
	pG.edgnum = 0;
	for(i=0; i<8; i++)
	{
		for(j=0; j<8; j++)
		{
			pG.matrix[i][j] = matrix[i][j];
			if(i!=j && matrix[i][j]!=INF)
			{
			  pG.edgnum++;
			}
		}
	}
	pG.edgnum /= 2;

	return pG;
}

/**
 * @brief D算法主程序
 *
 * @param pG
 * @param vs 起始点
 * @param dist[]最短路径
 * */
void dijkstra(Graph pG, int vs, int dist[])
{
	int i, j, k;
	int tmp;
	int flag[MAX];///标记搜索过的点
	int min;
	for(i=0; i<pG.vexnum; i++)
	{
		flag[i] = 0;
		dist[i] = pG.matrix[vs][i];
	}
	///对原点初始化
	dist[vs] = 0;
	flag[vs] = 1;
	///搜索pG.vexnum-1次,因为原点已经搜索过了
	for(i=1; i<pG.vexnum; i++)
	{
		min = INF;
		///找到起始点最近的点,并加入进去,标记.
		for(j=0; j<pG.vexnum; j++)	
		{
			if((flag[j]==0) && (dist[j]<min))
			{
			  min = dist[j];
			  k = j;
			}
		}
		flag[k] = 1;

		///更新dist[]中的路径大小
		for(j=0; j<pG.vexnum; j++)
		{
			tmp = (pG.matrix[k][j]==INF) ? INF : (min+pG.matrix[k][j]);
			if(flag[j]==0 && (tmp<dist[j]))
			{
				dist[j] = tmp;
			}
		}
	}

	printf("dijkstra(%c): \n", pG.vexs[vs]);
	for(i=0; i<pG.vexnum; i++)
	  printf("shortest(%c, %c)=%d\n", pG.vexs[vs], pG.vexs[i], dist[i]);
}

/**
 * @brief 主程序
 */
void main()
{
	int dist[MAX] = {0};
	Graph pG;
	pG = create_example_graph();
	dijkstra(pG, 3, dist);
}
