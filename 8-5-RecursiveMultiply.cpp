/*
 *不使用乘号计算乘法
 *思路：乘法实则是数相加，可使用递归，时间复杂度o(log n)
 * When someone create a thing with all of their hearts,
 * then the creature is given a soul.
 */

#include <stdio.h>  
#include <string.h>  
#include <stdlib.h>  
#include <math.h>

int minProductHelper(int smaller, int bigger)
{
	int halfProd, s;
	if (smaller == 0)
		return 0;
	if (smaller == 1)
		return bigger;
	s = smaller >> 1;
	halfProd = minProductHelper(s, bigger);
	
	if (smaller % 2)
		return halfProd + halfProd + bigger;
	else
		return halfProd + halfProd;
}

int minProduct(int a, int b)
{
	int smaller = a > b ? b : a;
	int bigger = a > b ? a : b;
	return minProductHelper(smaller, bigger);
}

int main()
{
	int a, b, multiply;
	scanf("%d %d", &a, &b);
	multiply = minProduct(a, b);
	printf("%d", multiply);

	getchar();
	return 0;
}



