/*
* https://www.acmicpc.net/problem/15663
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int res[9] = { 0, };
int num[9];
bool visit[9] = { false, };

void find(int idx) {
	if (idx == M) {
		for (int i = 0; i < M; i++)
			printf("%d ", res[i]);
		printf("\n");
		return;
	}

	int last = 0;

	for (int i = 0; i < N; i++) {
		if (visit[i])
			continue;
		if (last == num[i])
			continue;

		res[idx] = last = num[i];
		visit[i] = true;
		find(idx + 1);
		visit[i] = false;
	}
}

int main()
{
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++)
		scanf("%d", &num[i]);

	sort(num, num + N);

	find(0);
}
