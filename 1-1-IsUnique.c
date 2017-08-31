/* IsUnique.c 
 * 功能：判断一个字符串中字符是否唯一
 * 解法 加速字符集是a-z 
 *      借助bit vector/位向量，如果对应位是1则出错
 */

#include "stdafx.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

bool isUniqueChars(char * str)
{
	int len, i, check, val;
	len = strlen(str);
	check = 0;

	for (i = 0; i < len; i++)
	{
		val = str[i] - 'a';
		if(check & (1 << val) > 0)
			return false;
		else 
			check |= (1 << val);
	}

	return true;
}

int main(int argc, char* argv[])
{
	int len;
	char str[300];

	while(1)
	{
		gets(str); //gets 和 scanf接受结束后自动加'\0'

		if(! isUniqueChars(str))
			printf("Input string has all unique characters\n");
		else
			printf("Input string has repeated characters\n");
	}

	return 0;
}

