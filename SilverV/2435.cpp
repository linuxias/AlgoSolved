/*
* https://www.acmicpc.net/problem/2435
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <limits.h>

int main() {
	int N, K;
	int data[100];
	int sum = 0;
	int max_sum = -10000;

	scanf("%d %d", &N, &K);
	for (int i = 0; i < N; i++) {
		scanf("%d", &data[i]);
		sum += data[i];
		if (i + 1 >= K) {
			if (max_sum < sum)
				max_sum = sum;
			sum -= data[i - K + 1];
		}
	}

	printf("%d\n", max_sum);
	
	return 0;
}
