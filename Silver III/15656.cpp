/*
* https://www.acmicpc.net/problem/15656
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int res[9] = { 0, };
int num[9];

void find(int idx) {
	if (idx == M) {
		for (int i = 0; i < M; i++)
			printf("%d ", num[res[i]]);
		printf("\n");
		return;
	}

	for (int i = 0; i < N; i++) {
		res[idx] = i;
		find(idx + 1);
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
