/* basicLinkedList.c 
 * ���� �������� ����β����/ɾ
 * Tips 1 ������һ�ֱ�ʾ˳��ڵ�����ݽṹ�����ʱ��Ч�ʲ������飬��ɾ��ʱ��Ч����������
 *      2 �������� & ˫������
 *      3 �������� ע������ͷ
 *		4 ɾ���裺����ָ�� �޸�ָ�� �ڴ����
 *		5 ˫ָ��ⷨ��һ��������һ��������+��ϵ����һ������һ�������ı�����*��ϵ��
 *		6 ���ܻ�͵ݹ�һ��ʹ�ã����еݹ鶼��ת���ɵ������ݹ�ռ俪����
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

//��Ҫ�޸�ʱ��ע�⴫�Ĳ�����ָ��ĵ�ַ
void appendToTail(struct node * * head, struct node * newNode)
{
	struct node * *p;
	p =  head;
	
	while((*p) != NULL)
		p = &((*p)->next); //p�ǵ�ַ
	*p = newNode;          //�޸ĵ�ַ�ڵ����ݣ��ض���ָ��
	return ;
}

void deleteNode(struct node * * head, int val)
{
	struct node * * p, * * temp;
	p = head;

	//���Ҫɾ������ͷָ��
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

