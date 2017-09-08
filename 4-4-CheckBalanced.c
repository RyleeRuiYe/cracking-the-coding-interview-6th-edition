/* CheckBalanced.c 
 * 功能 给一个二叉树，检查是不是平衡二叉树（任一节点左右子树的高度差绝对值不大于1）
 * 思路 递归解法，返回值-子树高度；优化 当递归过程中某一个子树不符合则该树不符合——>该子树高度设为某大数，每次递归先判断
 * When someone creates something with all of their hearts,
 * then that creation is given a soul.
 */

#include "stdafx.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 9999

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

int checkHeight(struct TreeNode * root)
{
	int leftHeight, rightHeight;
	if(!root)
		return -1;

	leftHeight = checkHeight(root->left);
	if(leftHeight == MAX)
		return MAX;

	rightHeight = checkHeight(root->right);
	if(leftHeight == MAX)
		return MAX;

	if (leftHeight - rightHeight == 1 || rightHeight == leftHeight)
		return leftHeight + 1;
	else if (rightHeight - leftHeight == 1)
		return rightHeight + 1;
	else 
		return MAX;
}

int main(int argc, char* argv[])
{	
	int array[] = {1, 2};
	int i, arraySize;
	struct TreeNode * root = NULL;

	arraySize = sizeof(array)/ sizeof(array[0]);
	for(i =0; i < arraySize; i++)
		root = treeAdd(root, array[i]);

	if(MAX == checkHeight(root))
		printf("Not Balaced Tree\n");
	else
		printf("Balanced Tree\n");

	return 0;
}