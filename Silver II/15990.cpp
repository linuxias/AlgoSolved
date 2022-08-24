/*
* https://www.acmicpc.net/problem/15990
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

unsigned long long DP[100001][3] = {0,};

int main() {
	int N;
	scanf("%d", &N);

	DP[1][0] = 1;
	DP[1][1] = 0;
	DP[1][2] = 0;

	DP[2][0] = 0;
	DP[2][1] = 1;
	DP[2][2] = 0;

	DP[3][0] = 1;
	DP[3][1] = 1;
	DP[3][2] = 1;

	DP[4][0] = 2;
	DP[4][1] = 0;
	DP[4][2] = 1;

	while (N--) {
		int tmp = 0;
		scanf("%d", &tmp);

		if (DP[tmp][0] + DP[tmp][1] + DP[tmp][2] != 0) {
			printf("%llu\n", (DP[tmp][0] + DP[tmp][1] + DP[tmp][2]) % 1000000009);
		} else {
			for (int i = 5; i <= tmp; i++) {
				DP[i][0] = (DP[i - 1][1]  + DP[i - 1][2] ) % 1000000009;
				DP[i][1] = (DP[i - 2][0]  + DP[i - 2][2] ) % 1000000009;
				DP[i][2] = (DP[i - 3][0]  + DP[i - 3][1] ) % 1000000009;
			}

			printf("%llu\n", (DP[tmp][0] + DP[tmp][1] + DP[tmp][2]) % 1000000009);
		}
	}
	return 0;
}
