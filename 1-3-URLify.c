/* URLify.c 
 * ���� �������ַ��������пո��滻Ϊ%20 ����Դ�ַ������㹻�ռ�����
 * �ⷨ �Ӻ���ǰ�����ַ������Ӷ�����overwrite
 * When someone creates something with all of their heart,
 * then that creation is given a soul.
 */

#include "stdafx.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*���α�����һ�εó��ո��������һ�δӺ���ǰ�滻
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
		gets(str); //gets���Խ��տո��Իس�������ȡ��ʹ��'\0'��β
		len = strlen(str);
		printf("before: %s\n", str);

		replaceSpaces(str, len);
		
		printf("after: %s\n", str);
	}

	return 0;
}

