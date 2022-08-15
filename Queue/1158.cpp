/*
* https://www.acmicpc.net/problem/1158
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int arr[5001];

int main() {
	int N, K;
	scanf("%d %d", &N, &K);

	for (int i = 1; i < N; i++)
		arr[i] = i;

	arr[0] = N;
	int cur = 1;
	printf("<");
	for (int i = N; i > 1; i--) {
		(cur += (K - 1)) %= i;
		printf("%d, ", arr[cur]);
		for (int j = cur; j < i - 1; j++)
			arr[j] = arr[j + 1];
	}
	printf("%d>", arr[0]);
	return 0;
}
