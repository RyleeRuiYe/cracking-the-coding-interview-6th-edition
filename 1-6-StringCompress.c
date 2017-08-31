/* StringCompression.c 
 * ���� �Ը����ַ���ѹ��������aabcccccaaa����>a2b1c5a3�����ѹ���ַ�������ԭ�ַ������򷵻�ԭ�ַ���
 * �ⷨ ʹ������ѭ�����ȼ��ѹ����Ĵ�С������Ҫ��Ҫѹ��
 * ע�⣺�ַ�������β�����'\0'
 * When someone creates something with all of their heart,
 * then that creation is given a soul.
 */

#include "stdafx.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char * stringCompress(char * str1, char * str2)
{
	int len, compressedLen, i, index, count;
	len = strlen(str1);
	compressedLen = 0;
	for(i = 0; i < len; i++)
	{
		if(str1[i + 1] != str1[i])
		{
			compressedLen += 2;
		}
	}

	if(compressedLen >= len)
	{
		str2 = str1;
		str2[len] = '\0';
		return str1;
	}

	count = 0;
	for(i = 0, index = 0; i < len; i++)
	{
		count++;
		if(str1[i + 1] != str1[i])
		{
			str2[index] = str1[i];
			index++;
			str2[index] = count + '0';
			index++;
		}
			
	}
	str2[index] = '\0';
	return str2;

}

int main(int argc, char* argv[])
{
	char str1[300], str2[300];
	char * result;

	while(1)
	{
		printf("Input str\n");
		gets(str1); 

		result = stringCompress(str1, str2);
		printf("Compression result: %s\n", result);
	}

	return 0;
}

