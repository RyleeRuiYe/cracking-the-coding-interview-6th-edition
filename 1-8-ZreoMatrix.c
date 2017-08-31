/* ZeroMatrix.c 
 * ���� ����M*N���飬��ĳһλ��m,n����0����������m�к�n��ȫ����0
 * �ⷨ ��һ�α�������¼Ϊ0���кź��кţ��ڶ��Σ����ݼ�¼���кź��кŴ�����0
 * �Ż��⣺ʹ�õ�һ�к͵�һ�м�¼������ʹ�ö�������ݽṹ
 * When someone creates something with all of their heart,
 * then that creation is given a soul.
 */

#include "stdafx.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//��ά������Ϊ��������ֵ
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

	//����һ����û��0
	for(j = 0; j < 4; j++)
		if(matrix[0][j] == 0)
		{
			rowHasZero = 1;
			break;
		}

	//����һ����û��0
	for(i = 0; i < 3; i++)
		if(matrix[i][0] == 0)
		{
			colHasZero = 1;
			break;
		}

	//�����������Ԫ����û��0
	for(i = 1; i < 3; i++){
		for(j = 1; j < 4; j++){
			if(matrix[i][j] == 0)
			{
				matrix[0][j] = 0;
				matrix[i][0] = 0;
			}
		}
	}

	//����0
	for(j = 1; j < 4; j++)
	{
		if(matrix[0][j] == 0)
		{
			for(i = 1; i < 3; i++)
				matrix[i][j] =0;
		}
	}

	//����0
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
	//��ά���鸳ֵ
	int matrix[3][4]={1,2,0,3,4,5,0,7,8,9,10,11};
	printf("before\n");
	printMatrix(matrix);

	zeroMatrix(matrix);
	printf("after\n");
	printMatrix(matrix);
	return 0;
}

