/*
* https://www.acmicpc.net/problem/10819
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>

int N;
int input[9];
int res[9];
bool visit[9] = {false,};
int max = 0;

void find(int idx) {
	if (idx == N) {
		int sum = 0;
		for (int i = 0; i < N - 1; i++)
			sum += abs(res[i] - res[i + 1]);
		max = sum > max ? sum : max;
		return;
	}

	for (int i = 0; i < N; i++) {
		if (visit[i] == true)
			continue;
		visit[i] = true;
		res[idx] = input[i];
		find(idx + 1);
		visit[i] = false;
	}
}

int main() {
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &input[i]);
	}

	find(0);

	printf("%d\n", max);

	return 0;
}
