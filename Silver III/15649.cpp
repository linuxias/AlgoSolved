/*
* https://www.acmicpc.net/problem/15649
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int N, M;
bool visit[9] = { false, };
int res[9] = { 0, };

void find(int idx) {
	if (idx == M + 1) {
		for (int i = 1; i <= M; i++)
			printf("%d ", res[i]);
		printf("\n");
		return;
	}

	for (int i = 1; i <= N; i++) {
		if (visit[i])
			continue;
		visit[i] = true;
		res[idx] = i;
		find(idx + 1);
		visit[i] = false;
	}
}

int main()
{
	scanf("%d %d", &N, &M);

	find(1);
}
