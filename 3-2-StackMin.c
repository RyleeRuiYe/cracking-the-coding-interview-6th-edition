/* stackMin.c 
 * 功能 O(1) 时间返回stack最小值 
 * 思路 最小值的改变时机——出现更小的元素 可以每个元素都标记最小值，也可以使用stack记录最小值
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

int min(struct StackNode * minimum)
{
	if(!minimum)
		return 9999;
	return top(minimum);
}

void pushGeneral(struct StackNode * * data, struct StackNode * * minimum, int value)
{
	if(value <= min(* minimum))
		push(minimum, value);
	push(data, value);
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

void popGeneral(struct StackNode * * data, struct StackNode * * minimum)
{
	int value = pop(data);
	if(value == min(*minimum))
		pop(minimum);
	return;
}

int isEmpty(struct StackNode * * stack)
{
	if( (* stack) == NULL)
		return 1;
	else 
		return 0;
}

void destroyStack(struct StackNode * * stack)
{
	while(!isEmpty(stack))
		pop(stack);
}

void printStack(struct StackNode * stack)
{
	struct StackNode * p_node = stack;
	if(!p_node)
	{
		printf("An empty stack\n");
		return ;
	}
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
	struct StackNode * data = NULL;
	struct StackNode * minimum = NULL;
	pushGeneral(&data, &minimum, 3);
	pushGeneral(&data, &minimum, 4);
	pushGeneral(&data, &minimum, 5);
	pushGeneral(&data, &minimum, 2);
	pushGeneral(&data, &minimum, 1);
	printf("original stack, the mininum is %d\n", min(minimum));
	printStack(data);

	popGeneral(&data, &minimum);
	printf("After pop, the minumun is %d\n", min(minimum));
	printStack(data);
	popGeneral(&data, &minimum);
	printf("After pop, the minumun is %d\n", min(minimum));
	printStack(data);
	destroyStack(&data);
	return 0;
}
