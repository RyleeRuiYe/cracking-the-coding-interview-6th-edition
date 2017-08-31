/* basicLinkedList.c 
 * 功能 单向链表 （队尾）增/删
 * Tips 1 链表是一种表示顺序节点的数据结构，查的时间效率差于数组，增删的时间效率优于数组
 *      2 单向链表 & 双向链表
 *      3 链表问题 注意链表头
 *		4 删步骤：检查空指针 修改指针 内存管理
 *		5 双指针解法：一个快于另一个几步（+关系），一个是另一个步幅的倍数（*关系）
 *		6 可能会和递归一起使用（所有递归都能转化成迭代，递归空间开销大）
 * When someone creates something with all of their heart,
 * then that creation is given a soul.
 */

#include "stdafx.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node
{
	int value;
	struct node * next;
};

//需要修改时，注意传的参数是指针的地址
void appendToTail(struct node * * head, struct node * newNode)
{
	struct node * *p;
	p =  head;
	
	while((*p) != NULL)
		p = &((*p)->next); //p是地址
	*p = newNode;          //修改地址内的内容，重定向指针
	return ;
}

void deleteNode(struct node * * head, int val)
{
	struct node * * p, * * temp;
	p = head;

	//如果要删除的是头指针
	if((*p)->value == val)
	{
		*p = (*p)->next;
		//free(*head);
		return ;
	}
	while((*p)->next != NULL){
		if((*p)->next->value == val)
		{
			temp = &((*p)->next);
			*temp = (*p)->next->next;
			return ;
		}
		p = &((*p)->next);
	}
	return;
}

void printLinkedList(struct node * head)
{
	struct node * p;
	p = head;
	while(p != NULL){
		printf("%d-->", p->value);
		p = p->next;
	}
	printf("NULL\n");
}

int main(int argc, char* argv[])
{
	struct node * head, * newNode, *nNode2;
	head = NULL;
	printLinkedList(head);

	newNode = (struct node *)malloc(sizeof(struct node));
	if(newNode == NULL)
		exit(1);
	newNode->value = 1;
	newNode->next = NULL;

	appendToTail(&head, newNode);
	printLinkedList(head);

	nNode2 = (struct node *)malloc(sizeof(struct node));
	if(nNode2 == NULL)
		exit(1);
	nNode2->value = 2;
	nNode2->next = NULL;

	appendToTail(&head, nNode2);
	printLinkedList(head);

	deleteNode(&head, 2);
	printLinkedList(head);

	free(newNode);
	free(nNode2);

	
	return 0;
}

