/* RouteBetweenNodes.c 
 * 功能 找出给定有向图中，某两点之间是否有路径
 * 思路 广度优先搜索，以给定的节点为起点，在BFS过程中检查另一个节点
 *      是否找到；查询经过一个节点后，该节点要做相应标记
 * When someone creates something with all of their hearts,
 * then that creation is given a soul.
 */

#include "stdafx.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//辅助BFS的队列
struct Queue
{
	int head, tail, count;
	int data[128];
};

struct Queue * q;

int graph[6][6]=
{
	{0, 1, 0, 1, 0 ,0},
	{0, 0, 1, 0, 1, 0},
	{0, 0, 0, 1, 1, 1},
	{0, 1, 0, 0, 0, 0},
	{0, 0, 0, 1, 0, 0},
	{0, 0, 1, 0, 0, 0}
};

//标记图中元素是否被访问过，初始化为-1，如果被访问过则改为父节点的index
int mark[6];

//进队列
void enQueue(int n)
{
	q->data[q->tail ++] = n;
	q->count++;
}

//出队列
int deQueue(void)
{
	q->count--;
	return q->data[q->head++];
}

int bfs(int u, int v)
{
	enQueue(u);
	int i;
	int oldNode;
	mark[u] = u;

	if(u == v)
		return 1;
	while(q->count > 0)
	{
		oldNode = deQueue();
		if(oldNode == v)
			return 1;
		for(i = 0; i < 6; i++)
		{
			if(oldNode >= 0 && oldNode <6 && mark[i] == -1
			&& graph[oldNode][i] == 1)
			{
				mark[i] = oldNode;
				enQueue(i);
			}
		}
	}

	return 0;
}

void printPath(int u, int v)
{
	printf("Path: %d ", v);
	int i = mark[v];
	while(i != u)
	{
		printf("<-- %d ", i);
		i = mark[i];
	}
	printf("<-- %d\n", u);
	return ;
}

int main(int argc, char* argv[])
{	
	int u, v;
	q = (struct Queue *)malloc(sizeof(struct Queue));
	memset(mark, -1, 6 * sizeof(int));

	while(scanf("%d %d", &u, &v) != EOF)
	{
		memset(mark, -1, 6 * sizeof(int));
		q->head = q->tail= q->count = 0;
		if(bfs(u, v))
			printPath(u, v);
		else
			printf("不存在路径\n");
	}
	return 0;
}