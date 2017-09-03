/* sortStack.c 
 * 功能 stack元素排序，只用一个辅助stack，push pop isEmpty top
 * 思路 将原始stack的栈顶元素（无序），插入（先pop 再push 接着push）到有序的新stack
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

struct StackNode * s;
struct StackNode * r;

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

void sort(void)
{
	int temp;
	while(!isEmpty(&s))
	{
		temp = pop(&s);
		while(top(r) > temp && !isEmpty(&r))
			push(&s, pop(&r));
		push(&r, temp);
	}

	while(!isEmpty(&r))
		push(&s, pop(&r));
}

void destroyStack(void)
{
	while(!isEmpty(&s))
		pop(&s);
}

void printStack(void)
{
	struct StackNode * p_node = s;
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
	push(&s, 1);
	push(&s, 2);
	printStack();
	sort();
	printStack();
	destroyStack();
	return 0;
}
