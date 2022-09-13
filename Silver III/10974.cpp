/*
* https://www.acmicpc.net/problem/10974
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

int N;
int res[9] = { 0, };
bool visit[9] = { false, };

void find(int idx) {
	if (idx == N) {
		for (int i = 0; i < N; i++)
			printf("%d ", res[i]);
		printf("\n");
		return;
	}

	for (int i = 1; i <= N; i++) {
		if (visit[i] == true)
			continue;
		res[idx] = i;
		visit[i] = true;
		find(idx + 1);
		visit[i] = false;
	}
}

int main()
{
	scanf("%d", &N);

	find(0);
}
