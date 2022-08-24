/*
* https://www.acmicpc.net/problem/10844
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define MOD 1000000000

unsigned long long dp[101][10] = {0,};

int main() {
	
	for (int i = 1; i <= 9; i++)
		dp[1][i] = 1;

	int N;

	scanf("%d", &N);
	for (int i = 2; i <= N; i++) {
		for (int j = 0; j < 10; j++) {
			if (j == 0) {
				dp[i][j] = dp[i - 1][j+1];
			}
			else if (0 < j && j < 9) {
				dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % MOD;
			}
			else {
				dp[i][j] = dp[i - 1][j-1];
			}
		}
	}

	unsigned long long ans = 0;
	for (int i = 0; i < 10; i++)
		ans = (ans + dp[N][i]) % MOD;

	printf("%llu", ans);

	return 0;
}
