/*
* https://www.acmicpc.net/problem/15666
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int res[9] = { 0, };
int num[9];

void find(int idx, int val) {
	if (idx == M) {
		for (int i = 0; i < M; i++)
			printf("%d ", res[i]);
		printf("\n");
		return;
	}

	int last = 0;

	for (int i = val; i < N; i++) {
		if (last == num[i])
			continue;

		res[idx] = last = num[i];
		find(idx + 1, i);
	}
}

int main()
{
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++)
		scanf("%d", &num[i]);

	sort(num, num + N);

	find(0, 0);
}
