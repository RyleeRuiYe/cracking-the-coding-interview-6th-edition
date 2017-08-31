/* isPermutationOfPalindrome.c 
 * ���� �жϸ����ַ����ǲ��ǻ��ĵ��û�
 * �ⷨ ��ż������ͬ���ַ�������һ���������ַ�
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
	/*����bitVector*/
	for(i = 0; i < len; i++)
	{
		index = str[i] - 'a';
		mask = 1 << index;
		if((bitVector & mask) == 0)
			bitVector |= mask; //0��1
		else
			bitVector &= ~mask ; //1��0
	}

	/*���*/
	if(bitVector == 0 || (((bitVector - 1) & bitVector) == 0) )//ż����������ֻ��һ��1
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
		gets(str); //gets���Խ��տո��Իس�������ȡ��ʹ��'\0'��β

		if(isPermutationOfPalindrome(str))
			printf("It is permutation of palindrome\n", str);
		else
			printf("It is NOT permutation of palindrome\n", str);
	}

	return 0;
}

