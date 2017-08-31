/* CheckPermutation.c 
 * ���� ���������ַ������ж�һ���ǲ�����һ�����û�
 * �ⷨ 
 * ���䣺ASCII���128������չ��ASCII���256����
         A - 65(10����) 01000001   a - 97(10����) 0110001    
 */

#include "stdafx.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int permutation(char * str1, char * str2)
{
	int len1, len2, i, index;
	int letters[128] = {0};

	len1 = strlen(str1);
	len2 = strlen(str2);

	if (len1 != len2)
		return 0;

	for(i = 0; i < len1; i++)
	{
		index = (int) str1[i];
		letters[index]++;
	}

	for(i = 0; i < len2; i++)
	{
		index = (int)str2[i];
		letters[index]--;

		if(letters[index] < 0)
			return 0;
	}

	return 1;
}

int main(int argc, char* argv[])
{
	char str1[300], str2[300];
	int index;

	while(1)
	{
		printf("Input str1\n");
		gets(str1); 

		printf("Input str2\n");
		gets(str2);

		if(permutation(str1, str2))
			printf("str1 is a permutation of str2\n");
		else
			printf("str1 is NOT a permutation of str2\n");
	}

	return 0;
}

