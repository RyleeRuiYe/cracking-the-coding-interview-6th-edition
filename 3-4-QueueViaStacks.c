/* QueueViaStack.c 
 * 功能 两个stack实现一个queue
 * 思路 进stackNewest 出stackOldest 
 * Note 出的时候，如果stackOldest是空 需要把全部stackNewest元素移到stackOldest
 * When someone creates something with all of their heart,
 * then that creation is given a soul.
 */

#include "stdafx.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct StackNode
{
	int value;
	struct StackNode * next;
};

struct StackNode * stackNewest;
struct StackNode * stackOldest;
int stackNewestSize;
int stackOldestSize; 

void push(struct StackNode * * stack, int value)
{
	struct StackNode * new_node = NULL;
	new_node = (StackNode *)malloc(sizeof(struct StackNode));
	if(!new_node)
	{
		printf("malloc fail");
		return ; 
	}
	new_node->value = value;
	new_node->next = * stack;
	* stack = new_node;

}

int top(struct StackNode * data)
{
	if(!data)
	{
		printf("cannot top for empty stack\n");
		return -1;
	}
	return data->value;
}

int pop(struct StackNode * * stack)
{
	struct StackNode * old_top = * stack;
	int value = old_top->value;
	if(!old_top)
	{
		printf("empty list");
		return -1;
	}
	* stack = (* stack)->next;
	free(old_top);
	return value;
}

int isEmpty(struct StackNode * * stack)
{
	if( (* stack) == NULL)
		return 1;
	else 
		return 0;
}

void add(int value)
{
	push(&stackNewest, value);
	stackNewestSize++;
}

void shiftStacks(void)
{
	if(isEmpty(&stackOldest))
		while(!isEmpty(&stackNewest)){
			push(&stackOldest, pop(&stackNewest));
			stackNewestSize--;
			stackOldestSize++;
		}
}

int topQueue(void)
{
	shiftStacks();
	return top(stackOldest);
}

int remove(void)
{
	shiftStacks();
	stackOldestSize--;
	return pop(&stackOldest);
}

void destroyQueue()
{
	int queueSize = stackNewestSize + stackOldestSize;
	for(; queueSize > 0; queueSize--)
		printf("%d -->", remove());
	printf("end\n");
}

int main(int argc, char* argv[])
{	
	add(1);
	add(2);
	destroyQueue();
	return 0;
}
