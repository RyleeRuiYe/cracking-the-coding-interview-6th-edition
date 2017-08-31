/* StringCompression.c 
 * 功能 对给定字符串压缩，比如aabcccccaaa——>a2b1c5a3，如果压缩字符串大于原字符串，则返回原字符串
 * 解法 使用两次循环，先检测压缩后的大小，决定要不要压缩
 * 注意：字符串结束尾部添加'\0'
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

