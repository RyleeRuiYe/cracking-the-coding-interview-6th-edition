/* MinimalTree.c 
 * ���� ��һ���ź�������飬����һ�ø߶���С�Ķ�����������ǰ�����������
 * ˼· �߶���С����>���Һ��ӽڵ������������>�м�ڵ������ڵ�
 *      ������>�ݹ�
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

//Ϊ�½���ڵ㴴���洢�ṹ
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

//������������ÿ����Ӿֲ��е�Ϊ���ڵ�
struct TreeNode * createMinimalBST(int * arr, int start, int end)
{
	int mid;
	if(end < start)
		return NULL;

	mid = (start + end) / 2;
	struct TreeNode * root = newNode(arr[mid]);

	root->left = createMinimalBST(arr, start, mid -1 );
	root->right = createMinimalBST(arr, mid + 1, end);

	return root;
}

//���������ӡ����
void printInOrder(struct TreeNode * root)
{
	if (!root)
		return ;

	printInOrder(root->left);
	printf("%d\t", root->data);
	printInOrder(root->right);
	return ;
}



int main(int argc, char* argv[])
{	
	int array[] = {1, 2, 3, 4, 5};
	int size = sizeof(array) / sizeof(array[0]);
	struct TreeNode * root;
	root = createMinimalBST(array, 0, size -1 );
	printf("���������ӡ����\n");
	printInOrder(root);
	printf("\n");
	return 0;
}