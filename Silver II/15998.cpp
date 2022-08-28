/*
* https://www.acmicpc.net/problem/15988
*/


#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define MOD 1000000009

unsigned long long DP[1000001] = { 0, };

int main() {
	int N;
	scanf("%d", &N);

	DP[1] = 1;
	DP[2] = 2;
	DP[3] = 4;

	int max_tmp = 4;
	while (N--) {
		int tmp = 0;
		scanf("%d", &tmp);

		if (DP[tmp] != 0) {
			printf("%llu\n", DP[tmp]);
			continue;
		}

		for (int i = max_tmp; i <= tmp; i++) {
			if (DP[i] != 0)
				continue;
			DP[i] = (((DP[i - 1] + DP[i - 2]) % MOD) + DP[i - 3]) % MOD;
		}

		printf("%llu\n", DP[tmp]);
	}
	return 0;
}
