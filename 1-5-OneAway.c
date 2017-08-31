/* OneAway.c 
 * 功能 给定两个字符串，判定一个是不是由另一个一次增/删/改操作得出
 * 解法 增/减——长比短少一个字符，其余相同；改——只一个字符不同
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
int oneEditAway(char * str1, char * str2)
{
	int foundDifference = 0;
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	char * s_short, * s_long;
	int index1, index2;

	if( len1 - len2 != 1 && len2 - len1 != 1 && len1 != len2)
	{
		printf("length error\n");
		return 0;
	}

	s_short = len1 > len2 ? str2: str1;
	s_long = len1 > len2 ? str1: str2;

	len1 = strlen(s_short);
	len2 = strlen(s_long);

	for(index1 = 0, index2 = 0; index1 < len1; index1++)
	{
		if(s_short[index1] != s_long[index2]){
			if(foundDifference)
				return 0;
			foundDifference = 1;
		
		if (len1 != len2)
			index1--;
		}

		index2++;
	}
}

int main(int argc, char* argv[])
{
	char str1[300], str2[300];

	while(1)
	{
		printf("Input str1\n");
		gets(str1); 
		printf("Input str2\n");
		gets(str2);

		if(oneEditAway(str1, str2))
			printf("They are one edit away\n");
		else
			printf("They are NOT one edit away\n");
	}

	return 0;
}

