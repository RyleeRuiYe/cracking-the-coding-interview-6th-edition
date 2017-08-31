/* isPermutationOfPalindrome.c 
 * 功能 判断给定字符串是不是回文的置换
 * 解法 有偶数个相同的字符，至多一个奇数个字符
 * When someone creates something with all of their heart,
 * then that creation is given a soul.
 */

#include "stdafx.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
 *
 */
int isPermutationOfPalindrome(char * str)
{
	int bitVector = 0;
	int len = strlen(str);
	int i, index, mask;
	/*创建bitVector*/
	for(i = 0; i < len; i++)
	{
		index = str[i] - 'a';
		mask = 1 << index;
		if((bitVector & mask) == 0)
			bitVector |= mask; //0置1
		else
			bitVector &= ~mask ; //1置0
	}

	/*检测*/
	if(bitVector == 0 || (((bitVector - 1) & bitVector) == 0) )//偶数个，或者只有一个1
		return 1;
	else 
		return 0;
}

int main(int argc, char* argv[])
{
	char str[300];
	int len;

	while(1)
	{
		printf("Input str\n");
		gets(str); //gets可以接收空格，以回车结束读取，使用'\0'结尾

		if(isPermutationOfPalindrome(str))
			printf("It is permutation of palindrome\n", str);
		else
			printf("It is NOT permutation of palindrome\n", str);
	}

	return 0;
}

