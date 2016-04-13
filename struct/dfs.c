/**
 * @file dfs.c
 * @brief 深度优先搜索
 * @author cui
 * @version 1.0
 * @date 2016-04-13
 */
#include<stdio.h>
#include<stdlib.h>

#define MAX 100

/**
 * @name 图的结构体
 * @{ */
/**  @} */
typedef struct _graph
{
	char vexs[MAX];///节点数组
	int vexnum;///节点个数
	int edgnum;///边个数
	int matrix[MAX][MAX];///邻接矩阵
}Graph;

/**
 * @brief 得到字符所在位置
 *
 * @param G 结构体
 * @param vex 要插找的字符 *
 * @return 
 */
int get_position(Graph G, char vex)
{
	int i;
	for(i=0; i<G.vexnum; i++)
	  if(vex==G.vexs[i])
		return i;
	return -1;
}

/**
 * @brief 初始输入图
 *
 * @return 
 */
Graph create_graph()
{
	char vexs[8] = {'A','B','C','D','E','F','G'};
	char edgs[][2] = {
		{'A','C'},
		{'A','D'},
		{'A','F'},
		{'C','B'},
		{'C','D'},
		{'F','G'},
		{'G','E'}
	}; 
	Graph G;
	G.vexnum = sizeof(vexs)/sizeof(vexs[0]);
	G.edgnum = sizeof(edgs)/sizeof(edgs[0]);
	int i,p1,p2;
	for(i=0; i<G.vexnum; i++)
	  G.vexs[i] = vexs[i];
	///邻接矩阵初始化
	for(i=0; i<G.edgnum; i++)
	{
		p1 = get_position(G, edgs[i][0]);
		p2 = get_position(G, edgs[i][1]);

		G.matrix[p1][p2] = 1;
		G.matrix[p2][p1] = 1;
	}
	return G;
}

/**
 * @brief 得到图的第一个节点
 *
 * @param G
 * @param s
 *
 * @return 
 */
int first_vertix(Graph G, int s)
{
	int i;
	for(i=0; i<G.vexnum; i++)
	  if(G.matrix[s][i]==1)
		return i;
	return -1;
}

/**
 * @brief 得到图的下一个节点
 *
 * @param G
 * @param s 起始点
 * @param n 下一个节点 *
 * @return 
 */
int next_vertix(Graph G, int s, int n)
{
	int i;
	for(i=n+1; i<G.vexnum; i++)
		if(G.matrix[s][i]==1)
		  return i;
	return -1;
}

/**
 * @brief 搜索程序
 *
 * @param G
 * @param s
 * @param visited 访问标记
 */
void DFS(Graph G, int s, int* visited)
{
	int i;
	if(visited[s]==0)
	{
		printf("DFS: %c\n", G.vexs[s]);
		visited[s] = 1;
	}
	///遍历所有邻接节点
	for(i=first_vertix(G, s); i>=0; i=next_vertix(G, s, i))
	  if((visited[i]==0) && (G.matrix[s][i]==1))
	  {
		  printf("%c\n", G.vexs[i]);
		  visited[i] = 1;
		  DFS(G, i, visited);
	  }
}

/**
 * @brief 递归遍历
 *
 * @param G
 */
void DFSRecur(Graph G)
{
	int visited[MAX] = {0};
	int i;
	///查看是否有未遍历的点
	for(i=0; i<G.vexnum; i++)
	{
		printf("LOOP(%d): \n", i);
		if(visited[i]==0)
		DFS(G, i, visited);
	}
}
/**
 * @brief 主程序
 *
 * @return 
 */
int main()
{
	Graph G;
	G = create_graph();
	DFSRecur(G);
	return 0;
}
