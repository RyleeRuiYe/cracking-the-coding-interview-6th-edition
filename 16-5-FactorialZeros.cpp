/*
 * Factorial Zreos 计算输入值阶乘末尾0的个数
 * 思路：0——>5的个数
 * When someone create some thing with all of their hearts, 
 * then that creature is given a soul
 */
#include <stdio.h>
#include <stdlib.h>

int main() {
	int n, i, count = 0;
	scanf("%d", &n);
	if (n >= 0)
	{
		for (i = 5; n / i > 0; i *= 5)
			count += n / i;
		printf("%d! have %d trailing zeros\n", n, count);
	}
	else
		printf("error input\n");
		getchar();
}