/* MinimalTree.c 
 * 功能 给一个排好序的数组，创建一棵高度最小的二叉搜索树（前序遍历递增）
 * 思路 高度最小——>左右孩子节点数量相近——>中间节点做根节点
 *      树——>递归
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

//创建二叉树，每次添加局部中点为根节点
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



int main(int argc, char* argv[])
{	
	int array[] = {1, 2, 3, 4, 5};
	int size = sizeof(array) / sizeof(array[0]);
	struct TreeNode * root;
	root = createMinimalBST(array, 0, size -1 );
	printf("先序遍历打印数：\n");
	printInOrder(root);
	printf("\n");
	return 0;
}