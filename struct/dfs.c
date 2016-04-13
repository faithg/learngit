/**
 * @file dfs.c
 * @brief �����������
 * @author cui
 * @version 1.0
 * @date 2016-04-13
 */
#include<stdio.h>
#include<stdlib.h>

#define MAX 100

/**
 * @name ͼ�Ľṹ��
 * @{ */
/**  @} */
typedef struct _graph
{
	char vexs[MAX];///�ڵ�����
	int vexnum;///�ڵ����
	int edgnum;///�߸���
	int matrix[MAX][MAX];///�ڽӾ���
}Graph;

/**
 * @brief �õ��ַ�����λ��
 *
 * @param G �ṹ��
 * @param vex Ҫ���ҵ��ַ� *
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
 * @brief ��ʼ����ͼ
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
	///�ڽӾ����ʼ��
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
 * @brief �õ�ͼ�ĵ�һ���ڵ�
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
 * @brief �õ�ͼ����һ���ڵ�
 *
 * @param G
 * @param s ��ʼ��
 * @param n ��һ���ڵ� *
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
 * @brief ��������
 *
 * @param G
 * @param s
 * @param visited ���ʱ��
 */
void DFS(Graph G, int s, int* visited)
{
	int i;
	if(visited[s]==0)
	{
		printf("DFS: %c\n", G.vexs[s]);
		visited[s] = 1;
	}
	///���������ڽӽڵ�
	for(i=first_vertix(G, s); i>=0; i=next_vertix(G, s, i))
	  if((visited[i]==0) && (G.matrix[s][i]==1))
	  {
		  printf("%c\n", G.vexs[i]);
		  visited[i] = 1;
		  DFS(G, i, visited);
	  }
}

/**
 * @brief �ݹ����
 *
 * @param G
 */
void DFSRecur(Graph G)
{
	int visited[MAX] = {0};
	int i;
	///�鿴�Ƿ���δ�����ĵ�
	for(i=0; i<G.vexnum; i++)
	{
		printf("LOOP(%d): \n", i);
		if(visited[i]==0)
		DFS(G, i, visited);
	}
}
/**
 * @brief ������
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
