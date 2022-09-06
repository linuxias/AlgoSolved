/*
* https://www.acmicpc.net/problem/15650
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int N, M;
int res[9] = { 0, };

void find(int idx, int val) {
	if (idx == M) {
		for (int i = 0; i < M; i++)
			printf("%d ", res[i]);
		printf("\n");
		return;
	}

	for (int i = val + 1; i <= N; i++) {
		res[idx] = i;
		find(idx + 1, i);
	}
}

int main()
{
	scanf("%d %d", &N, &M);

	find(0, 0);
}
