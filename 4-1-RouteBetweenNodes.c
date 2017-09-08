/* RouteBetweenNodes.c 
 * ���� �ҳ���������ͼ�У�ĳ����֮���Ƿ���·��
 * ˼· ��������������Ը����Ľڵ�Ϊ��㣬��BFS�����м����һ���ڵ�
 *      �Ƿ��ҵ�����ѯ����һ���ڵ�󣬸ýڵ�Ҫ����Ӧ���
 * When someone creates something with all of their hearts,
 * then that creation is given a soul.
 */

#include "stdafx.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//����BFS�Ķ���
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

//���ͼ��Ԫ���Ƿ񱻷��ʹ�����ʼ��Ϊ-1����������ʹ����Ϊ���ڵ��index
int mark[6];

//������
void enQueue(int n)
{
	q->data[q->tail ++] = n;
	q->count++;
}

//������
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
			printf("������·��\n");
	}
	return 0;
}