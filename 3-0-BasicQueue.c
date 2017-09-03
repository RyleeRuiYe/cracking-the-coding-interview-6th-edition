/* basicQueue.c 
 * ���� 
 * When someone creates something with all of their heart,
 * then that creation is given a soul.
 */

#include "stdafx.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct QueueNode
{
	int value;
	struct QueueNode * next;
};

struct QueueNode * head;
struct QueueNode * tail;

//����β �������
void add(int value)
{
	struct QueueNode * new_node = NULL;
	new_node = (QueueNode *)malloc(sizeof(struct QueueNode));
	if(!new_node)
	{
		printf("malloc fail");
		return ; 
	}
	new_node->value = value;
	new_node->next = NULL;
	
	if(head)           //ע���ʼ�� head�ڵ�
		head->next = new_node;
	head = new_node;
	if(!tail)
		tail = head;    //��һ���ڵ���ӽ�����ʱ��
}

//����ͷ ���г���
void remove(void)
{
	struct QueueNode * old_top = tail;
	if(!old_top)
	{
		printf("empty list");
		return;
	}
	tail = tail->next;
	if(!tail)
		head = NULL; //��ֹҰָ�룬��ʱ��ָ��ָ�����һ��Ԫ�أ�����һ����ɾ�����һ��Ԫ��
	free(old_top);
}

int top(void)
{
	if(!tail)
	{	
		printf("empty list");
		return -1;
	}
	return tail->value;
}

int isEmpty(void)
{
	return tail == NULL;
}

void destroyQueue(void)
{
	while(!isEmpty())
		remove();
}

void printQueue(void)
{
	struct QueueNode * p_node = tail;
	if(!p_node)
	{
		printf("An empty queue\n");
		return ;
	}
	printf("END <--");
	while(p_node)
	{
		printf("%d <--", p_node->value);
		p_node = p_node->next;
	}
	printf("Head\n");
	return;
}

int main(int argc, char* argv[])
{	
	printQueue();
	add(1);
	add(2);
	add(3);
	printQueue();
	remove();
	printQueue();
	destroyQueue();
	return 0;
}

