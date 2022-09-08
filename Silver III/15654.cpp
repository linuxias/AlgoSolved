/*
* https://www.acmicpc.net/problem/15654
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int visit[9] = { false, };
int res[9] = { 0, };
int num[9];

void find(int idx, int val) {
	if (idx == M) {
		for (int i = 0; i < M; i++)
			printf("%d ", num[res[i]]);
		printf("\n");
		return;
	}

	for (int i = 0; i < N; i++) {
		if (visit[i] == true)
			continue;
		res[idx] = i;
		visit[i] = true;
		find(idx + 1, i);
		visit[i] = false;
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
