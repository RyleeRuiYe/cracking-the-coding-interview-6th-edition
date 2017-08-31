/* IsUnique.c 
 * ���ܣ��ж�һ���ַ������ַ��Ƿ�Ψһ
 * �ⷨ �����ַ�����a-z 
 *      ����bit vector/λ�����������Ӧλ��1�����
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
		gets(str); //gets �� scanf���ܽ������Զ���'\0'

		if(! isUniqueChars(str))
			printf("Input string has all unique characters\n");
		else
			printf("Input string has repeated characters\n");
	}

	return 0;
}

