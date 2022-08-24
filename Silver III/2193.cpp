/*
 * https://www.acmicpc.net/problem/2193
 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef unsigned long long ull;

int main()
{
	int N;
	int i, j;
	ull zero, one, tmp = 0;

	zero = 0;
	one = 1;

	scanf("%d", &N);

	for (i = 2; i <= N; i++) {
		tmp = one;
		one = zero;
		zero = zero + tmp;
	}

	printf("%llu\n", zero+one);

	return 0;
}
