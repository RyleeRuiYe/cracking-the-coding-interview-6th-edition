/* flexibleThreeInOne.c 
 * 功能 使用一个数组实现三个stack 
 * 每个stack大小可根据实际情形扩展
 * When someone creates something with all of their heart,
 * then that creation is given a soul.
 */

#include "stdafx.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct StackInfo
{
	int start;
	int size;     //已经存入数据量
	int capacity; //容量
};

struct StackInfo * head [3];//指针数组，[]优先级高于* 
int values[300];
int valLen;

//创建堆栈
void MultiStack(int defaultSize)
{
	int i;
	for(i = 0; i < 3; i++)
	{
		head[i] = (StackInfo *)malloc(sizeof(StackInfo));
		if(!head[i])
		{
			printf("malloc fail\n");
			return;
		}
		head[i]->start = defaultSize * i;
		head[i]->capacity = defaultSize;
		head[i]->size = 0;
	}
	valLen = 3 * defaultSize;
}

//调整index的值，使其范围满足0 ~ valLen - 1，环形数组
int adjustIndex(int index)
{
	int max = valLen;
	return index % max;
}

//检查是否在一个stack中
int isWithinStackCapacity(int stackNum, int index)
{
	int contiguousIndex = index < head[stackNum]->start ? index + valLen : index;
	int end = head[stackNum]->start + head[stackNum]->capacity;
	if(index < 0 || index >= valLen)
		return 0;
	if(head[stackNum]->start < contiguousIndex && contiguousIndex < end)
		return 1;
	else 
		return 0;
}

//stack中最大容量下标
int lastCapacityIndex(int stackNum)
{
	return adjustIndex(head[stackNum]->start + head[stackNum]->capacity - 1);
}

//stack栈顶下标
int lastElementIndex(int stackNum)
{
	return adjustIndex(head[stackNum]->start + head[stackNum]->size - 1);
}

//stack是否已满
int isFull(int stackNum)
{
	if(head[stackNum]->size == head[stackNum]->capacity)
		return 1;
	else 
		return 0;
}

//stack是否为空
int isEmpty(int stackNum)
{
	if(head[stackNum]->size == 0)
		return 1;
	else
		return 0;
}

//数组中有多少数据
int numberOfElements()
{
	int size = 0, i;
	for(i = 0; i < 3; i++)
	{
		size += head[i]->size;
	}
	return size;
}

//数组是否已满
int allStackAreFull()
{
	if( numberOfElements() == valLen)
		return 1;
	else
		return 0;
}

/*通过相邻的后一个stack整体后移一位来增加stack的capacity；
 *相邻stack空间已满，则移动其后的stack
 */
void shift(int stackNum)
{
	int index;
	if(head[stackNum]->size >= head[stackNum]->capacity)
	{
		shift((stackNum + 1)%3);
		head[stackNum]->capacity++;
	}
	index = lastCapacityIndex(stackNum);
	while(isWithinStackCapacity(stackNum, index))
	{
		values[index] = values[adjustIndex(index - 1)];
		index = adjustIndex(index - 1);
	}
	values[head[stackNum]->start] = 0;
	head[stackNum]->start = adjustIndex(head[stackNum]->start + 1);
	head[stackNum]->capacity--;
}

//相邻stack后移一位
void expand(int stackNum)
{
	shift((stackNum + 1)%3);
	head[stackNum]->capacity++;
}

void push(int stackNum, int value)
{
	if(allStackAreFull())
	{
		printf("No space to store\n");
		return;
	}

	if(isFull(stackNum))
		expand(stackNum);
	
	head[stackNum]->size++;
	values[lastElementIndex(stackNum)] = value;
}

void pop(int stackNum)
{
	if(isEmpty(stackNum))
	{
		printf("stack%d is empty\n", stackNum);
		return ;
	}

	values[lastElementIndex(stackNum)] = 0;
	head[stackNum]->size--;
}

void destroyStackInfo(void)
{
	int i;
	for(i = 0; i < 3; i++)
	{
		free(head[i]);
		head[i] = NULL;
	}
	valLen = 0;
}

void printMultiStack(void)
{
	int i, j, start, index;

	for(i = 0; i < 3; i++)
	{
		if(!head[i])
		{
			printf("No stack exists\n");
			return;
		}
		printf("stack%d   start:%d   size:%d   capacity:%d\n", i, head[i]->start, head[i]->size, head[i]->capacity);
		start = head[i]->start;

		for(j = 0; j < head[i]->size; j++)
		{
			index = adjustIndex(start + j);
			printf("%d  ", values[index]);
		}
		printf("\n");
	}
	return;
}

int main(int argc, char* argv[])
{	
	int defaultSize = 5;
	MultiStack(defaultSize);
	push(2, 1);
	push(2, 2);
	push(2, 3);
	push(2, 4);
	push(2, 5);
	push(2, 6);
	printMultiStack();
	destroyStackInfo();
	return 0;
}

