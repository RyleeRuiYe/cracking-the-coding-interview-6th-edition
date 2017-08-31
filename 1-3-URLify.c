/* URLify.c 
 * 功能 将输入字符串中所有空格替换为%20 假设源字符串有足够空间容纳
 * 解法 从后向前操作字符串，从而避免overwrite
 * When someone creates something with all of their heart,
 * then that creation is given a soul.
 */

#include "stdafx.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*两次遍历：一次得出空格的数量，一次从后向前替换
 */
void replaceSpaces(char * str, int len)
{
	int i, spaceCount, index;
	spaceCount = 0;

	for( i = 0; i < len; i++)
	{
		if(str[i] == ' ')
			spaceCount++;
	}
	printf("Total spaceCount is %d\n", spaceCount);

	index = len + spaceCount * 2;
	str[index] = '\0';
	for( i = len - 1; i >= 0; i--){
		if(str[i] == ' ')
		{
			str[index - 1] = '0';
			str[index - 2] = '2';
			str[index - 3] = '%';
			index -= 3;
		}
		else
		{
			str[index - 1] = str[i];
			index--;
		}
	}
}

int main(int argc, char* argv[])
{
	char str[300];
	int len;

	while(1)
	{
		printf("Input str\n");
		gets(str); //gets可以接收空格，以回车结束读取，使用'\0'结尾
		len = strlen(str);
		printf("before: %s\n", str);

		replaceSpaces(str, len);
		
		printf("after: %s\n", str);
	}

	return 0;
}

