/*
* https://www.acmicpc.net/problem/17404
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define MAX_VAL 1000001
#define MIN(a,b) (a > b ? b : a)

int data[1001][3] = { 0, };
int st0, st1, st2;

int main() {
	int ans = MAX_VAL;
	int N;
	scanf("%d", &N);

	for (int i = 1; i <= N; i++)
		scanf("%d %d %d", &data[i][0], &data[i][1], &data[i][2]);
	

	for (int i = 0; i <= 2; i++) {
		int dp[1001][3] = { 0, };
		for (int j = 0; j <= 2; j++) {
			if (i == j)
				dp[1][i] = data[1][i];
			else
				dp[1][j] = MAX_VAL;
		}

		for (int j = 2; j <= N; j++) {
			dp[j][0] = MIN(dp[j - 1][1], dp[j - 1][2]) + data[j][0];
			dp[j][1] = MIN(dp[j - 1][0], dp[j - 1][2]) + data[j][1];
			dp[j][2] = MIN(dp[j - 1][0], dp[j - 1][1]) + data[j][2];
		}

		for (int j = 0; j <= 2; j++) {
			if (i == j)
				continue;
			ans = MIN(ans, dp[N][j]);
		}
	}

	printf("%d\n", ans);
	return 0;
}
