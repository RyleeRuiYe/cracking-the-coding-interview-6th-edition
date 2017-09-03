/* basicStack.c 
 * 功能 链表实现栈 进栈/出栈/返回栈顶/判断是够为空
 * 实现 用单向链表 对头插入
 * When someone creates something with all of their heart,
 * then that creation is given a soul.
 */

#include "stdafx.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct stack_node
{
	int value;
	struct stack_node * next;
};

struct stack_node *stack;

void push(int value)
{
	struct stack_node * new_node = NULL;
	new_node = (stack_node *)malloc(sizeof(struct stack_node));
	if(!new_node)
	{
		printf("malloc fail");
		return ; 
	}
	new_node->value = value;
	new_node->next = stack;
	stack = new_node;
}

void pop(void)
{
	struct stack_node * old_top = stack;
	if(!old_top)
	{
		printf("empty list");
		return;
	}
	stack = stack->next;
	free(old_top);
}

int top(void)
{
	if(!stack)
	{	
		printf("empty list");
		return -1;
	}
	return stack->value;
}

int isEmpty(void)
{
	return stack == NULL;
}

void destroyStack(void)
{
	while(!isEmpty())
		pop();
}

void printStack(void)
{
	struct stack_node * p_node = stack;
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
	printStack();
	push(1);
	push(2);
	push(3);
	push(4);
	printf("Top: %d\n", top());
	printf("After push: ");
	printStack();
	destroyStack();
	return 0;
}

