/* ZeroMatrix.c 
 * 功能 输入M*N数组，若某一位（m,n）是0，则其所在m行和n列全部置0
 * 解法 第一次遍历，记录为0的行号和列号；第二次，根据记录的行号和列号处理置0
 * 优化解：使用第一行和第一列记录，而不使用额外的数据结构
 * When someone creates something with all of their heart,
 * then that creation is given a soul.
 */

#include "stdafx.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//二维数组作为函数参数值
void printMatrix(int matrix[3][4])
{
	int rows, columns;

	for(rows = 0; rows < 3; rows++)
	{
		for(columns = 0; columns < 4; columns++)
		{
			printf("%d\t", matrix[rows][columns]);
		}
		printf("\n");
	}
}

void zeroMatrix(int matrix[3][4])
{
	int rowHasZero = 0;
	int colHasZero = 0;
	int i, j;

	//检查第一行有没有0
	for(j = 0; j < 4; j++)
		if(matrix[0][j] == 0)
		{
			rowHasZero = 1;
			break;
		}

	//检查第一列有没有0
	for(i = 0; i < 3; i++)
		if(matrix[i][0] == 0)
		{
			colHasZero = 1;
			break;
		}

	//检查其余数组元素有没有0
	for(i = 1; i < 3; i++){
		for(j = 1; j < 4; j++){
			if(matrix[i][j] == 0)
			{
				matrix[0][j] = 0;
				matrix[i][0] = 0;
			}
		}
	}

	//列置0
	for(j = 1; j < 4; j++)
	{
		if(matrix[0][j] == 0)
		{
			for(i = 1; i < 3; i++)
				matrix[i][j] =0;
		}
	}

	//列置0
	for(i = 1; i < 3; i++)
	{
		if(matrix[i][0] == 0)
		{
			for(j = 1; j < 4; j++)
				matrix[i][j] = 0;
		}
	}

	if(rowHasZero)
		for(j = 0; j < 4; j++)
			matrix[0][j] = 0;

	if(colHasZero)
		for(i = 0; i < 3; i++)
			matrix[i][0] = 0;
}

int main(int argc, char* argv[])
{
	//二维数组赋值
	int matrix[3][4]={1,2,0,3,4,5,0,7,8,9,10,11};
	printf("before\n");
	printMatrix(matrix);

	zeroMatrix(matrix);
	printf("after\n");
	printMatrix(matrix);
	return 0;
}

