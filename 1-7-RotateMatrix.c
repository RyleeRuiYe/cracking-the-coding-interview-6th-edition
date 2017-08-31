/* RotateMatrix.c 
 * ���� ����ת4*4���飨������תŶ��
 * �ⷨ �ֳ�4/2=2�㣬������Ǩ��
 * When someone creates something with all of their heart,
 * then that creation is given a soul.
 */

#include "stdafx.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//��ά������Ϊ��������ֵ
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
			temp = str[first][i]; //�洢����
			str[first][i] = str[last - offset][first];//����Ƶ�����
			str[last - offset][first] = str[last][last - offset];//�����Ƶ����
			str[last][last-offset] = str[i][last];//�ұ��Ƶ��±�
			str[i][last] = temp;
		}
	}
}

int main(int argc, char* argv[])
{
	//��ά���鸳ֵ
	char str[4][4]={'a','b','c','d','e','f','g','h','0','1','2','3','4','5','6','7'};
	printf("before\n");
	printMatrix(str);//��ά������Ϊ��������

	rotateMatrix(str);
	printf("after\n");
	printMatrix(str);

	return 0;
}

