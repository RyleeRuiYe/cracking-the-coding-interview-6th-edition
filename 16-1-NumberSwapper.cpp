/*
 * NumberSwapper不用临时变量交互两个数
 * 思路：
 * When someone create some thing with all of their hearts, 
 * then that creature is given a soul
 */
#include <stdio.h>
#include <stdlib.h>



int main()
{
	int a, b;
	scanf("%d %d", &a, &b);
	
	a = a + b;
	b = a - b;
	a = a - b;
	printf("a = %d\tb = %d\n", a, b);
	
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
	printf("a = %d\tb = %d\n", a, b);

	getchar();
	return 0;
}


