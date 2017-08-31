/* RotateMatrix.c 
 * 功能 左旋转4*4数组（整体旋转哦）
 * 解法 分成4/2=2层，逐层逐边迁移
 * When someone creates something with all of their heart,
 * then that creation is given a soul.
 */

#include "stdafx.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//二维数组作为函数参数值
void printMatrix(char str[4][4])
{
	int rows, columns;

	for(rows = 0; rows < 4; rows++)
	{
		for(columns = 0; columns < 4; columns++)
		{
			printf("%c\t", str[rows][columns]);
		}
		printf("\n");
	}
}

void rotateMatrix(char str[4][4])
{
	int n = 4, layer, first, last, offset, i;
	char temp;

	for(layer = 0; layer < n/2; layer++)
	{
		first = layer;
		last = n - 1 -layer;

		for(i = first; i < last; i++){
			offset = i - first;
			temp = str[first][i]; //存储上面
			str[first][i] = str[last - offset][first];//左边移到上面
			str[last - offset][first] = str[last][last - offset];//下面移到左边
			str[last][last-offset] = str[i][last];//右边移到下边
			str[i][last] = temp;
		}
	}
}

int main(int argc, char* argv[])
{
	//二维数组赋值
	char str[4][4]={'a','b','c','d','e','f','g','h','0','1','2','3','4','5','6','7'};
	printf("before\n");
	printMatrix(str);//二维数组作为参数传递

	rotateMatrix(str);
	printf("after\n");
	printMatrix(str);

	return 0;
}

