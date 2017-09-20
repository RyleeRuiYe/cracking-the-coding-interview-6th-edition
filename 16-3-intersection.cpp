/*
 * Intersection 给出连个直线段，判断是否有相交点，有的话输出相交点
 * 思路：
 * When someone create some thing with all of their hearts, 
 * then that creature is given a soul
 */
#include <stdio.h>
#include <stdlib.h>

struct point {
	double x;
	double y;
};

struct line {
	double slope;
	double yintercept;
	struct point start;
	struct point end;
};

void getLine(struct point start, struct point end, struct line *target)
{
	(*target).slope = (start.y - end.y) / (start.x - end.x);
	(*target).yintercept = end.y - (*target).slope * end.x;
	(*target).start = start.x < end.x ? start : end;
	(*target).end = start.x < end.x ? end : start;
	return;
}

int isBetween(double start, double mid, double end) 
{
	if (start < end)
		if (start <= mid && mid <= end)
			return 1;
		else
			return 0;
	else
		if (start >= mid && mid >= end)
			return 1;
		else
			return 0;
}

int intersection(struct line line1, struct line line2, struct point * result)
{
	double x, y;
	//斜率相同时
	if (line1.slope == line2.slope)
		if (line1.yintercept == line2.yintercept &&
			isBetween(line1.start.x, line2.start.x, line1.end.x))
		{
			*result = line2.start;
			return 1;
		}
		else
			return 0;
	//计算相交点
	x = (line2.yintercept - line1.yintercept) / (line1.slope - line2.slope);
	y = x * line1.slope + line1.yintercept;

	//检测是否在线上
	if (isBetween(line1.start.x, x, line1.end.x) &&
		isBetween(line2.start.x, x, line2.end.x))
	{
		(*result).x = x;
		(*result).y = y;
		return 1;
	}
	return 0;
}

int main() {
	struct point line1Start, line1End, line2Start, line2End, result;
	struct line line1, line2;
	int i;

	scanf("%lf %lf", &line1Start.x, &line1Start.y);
	scanf("%lf %lf", &line1End.x, &line1End.y);	
	scanf("%lf %lf", &line2Start.x, &line2Start.y);
	scanf("%lf %lf", &line2End.x, &line2End.y);

	getLine(line1Start, line1End, &line1);
	getLine(line2Start, line2End, &line2);
	printf("y = %lf * y + %lf\n", line1.slope, line1.yintercept);
	printf("y = %lf * y + %lf\n", line2.slope, line2.yintercept);

	if(line1.start.x < line2.start.x)
		i = intersection(line1, line2, &result);
	else
		i = intersection(line2, line1, &result);

	if (i)
		printf("intersection.x = %lf\tintersection.y=%lf\n", result.x, result.y);
	else
		printf("There is no intersection\n");

	getchar();



}