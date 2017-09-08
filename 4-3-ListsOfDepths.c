/* ListOfDepth.c 
 * 功能 给一个二叉树，根据同一层节点创建链表（N层则共有N个链表）
 * 思路 1 中序搜索遍历，传递当前层做参数
        2 宽度优先搜索，遍历上一层链表，创建当前层链表 （思路更直接）
 * When someone creates something with all of their hearts,
 * then that creation is given a soul.
 */

#include "stdafx.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct TreeNode
{
	int data;
	struct TreeNode * left, * right;
};

struct LinkListNode{
	struct TreeNode * node;
	struct LinkListNode * next;
};

int ArraySize;

//为新进入节点创建存储结构
struct TreeNode * newNode(int data)
{
	struct TreeNode * node = (struct TreeNode *)malloc(sizeof(TreeNode));
	if(!node){
		printf("malloc fail\n");
		return NULL;
	}
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	return node;
}

//创建二叉树
struct TreeNode * treeAdd(struct TreeNode * root, int value)
{
	if(!root)
		root = newNode(value);
	else if(value > root->data)
		root->right = treeAdd(root->right, value);
	else
		root->left = treeAdd(root->left, value);
	return root;
}

//先序遍历打印出树
void printInOrder(struct TreeNode * root)
{
	if (!root)
		return ;

	printInOrder(root->left);
	printf("%d\t", root->data);
	printInOrder(root->right);
	return ;
}

void listAdd(struct LinkListNode * * head, struct TreeNode * node)
{
	if(!node)
		return ;
	struct LinkListNode * temp = (struct LinkListNode *)malloc(sizeof(struct LinkListNode));
	temp->node = node;
	temp->next = *head;
	*head = temp;
}

void createLevelLinkedListRecurse(struct TreeNode * root, struct LinkListNode * *array, int level)
{
	if(!root)
		return ;
	if(ArraySize == level)
		ArraySize++;
	listAdd(&array[level], root);

	createLevelLinkedListRecurse(root->left, array, level + 1);
	createLevelLinkedListRecurse(root->right, array, level + 1);
}

void createLevelLinkedListBSF(struct TreeNode * root, struct LinkListNode * * array)
{
	int size = 0;
	struct LinkListNode * current = NULL;
	struct LinkListNode * parent = NULL;
	
	if(!root)
		return;
	listAdd(&array[size], root);
	current = array[size];
	while(current)
	{
		parent = array[size];
		size++;
		current = array[size];
		while( parent)
		{
			listAdd(&array[size], parent->node->left);
			listAdd(&array[size], parent->node->right);
			parent = parent->next;
		}
	}
}

void printList(struct LinkListNode * * array)
{
	int i;
	struct LinkListNode * temp;

	for(i = 0; i< ArraySize; i++)
	{
		printf("Level %d: ", i);
		temp = array[i];
		while(temp){
			printf("%d<--", temp->node->data);
			temp = temp->next;
		}
		printf("head\n");
	}
}

int main(int argc, char* argv[])
{	
	int array[] = {2, 1, 3};
	int i, arraySize;
	struct TreeNode * root = NULL;
	struct LinkListNode * listArray [10] = {NULL};//指针数组，[]优先级更高，数组有10个元素，每个元素都是指针
	arraySize = sizeof(array)/ sizeof(array[0]);
	for(i =0; i < arraySize; i++)
		root = treeAdd(root, array[i]);
	createLevelLinkedListRecurse(root, listArray, 0);
	printList(listArray);
	memset(listArray, 0, 10 * sizeof(struct LinkListNode *));
	createLevelLinkedListBSF(root, listArray);
	printList(listArray);
	return 0;
}