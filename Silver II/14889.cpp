/*
* https://www.acmicpc.net/problem/14889
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>

int N;
int row_col_sum[22] = {0,};
int total = 0;
int diff_min = 0x7ffffff;

void find(int idx, int team_total, int val) {
	if (team_total == N / 2) {
		diff_min = diff_min < abs(val) ? diff_min : abs(val);
		return;
	}

	if (idx < N -1) {
		find(idx + 1, team_total + 1, val - row_col_sum[idx]);
		find(idx + 1, team_total, val);
	}
}

int main() {
	scanf("%d", &N);

	int tmp;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &tmp);
			total += tmp;
			row_col_sum[i] += tmp;
			row_col_sum[j] += tmp;
		}
	}

	find(0, 0, total);
	printf("%d\n", diff_min);
	return 0;
}

#if 0

int N;
int weight[21][21];
bool visit[21] = {false,};
int diff_min = 1000000;

void find(int idx, int val) {
	if (idx == N / 2) {
		int sum_a = 0, sum_b = 0;
		for (int i = 0; i < N; i++) {
			for (int j = i + 1; j < N; j++) {
				if (visit[i] == true && visit[j] == true)
					sum_a += (weight[i][j] + weight[j][i]);
				else if (visit[i] == false && visit[j] == false)
					sum_b += (weight[i][j] + weight[j][i]);
			}
		}

		diff_min = diff_min < abs(sum_a - sum_b) ? diff_min : abs(sum_a - sum_b);

		return;
	}

	for (int i = val; i < N; i++) {
		if (visit[i] == true)
			continue;
		visit[i] = true;
		find(idx + 1, i + 1);
		visit[i] = false;
	}
}

int main() {
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &weight[i][j]);
		}
	}

	find(0, 0);

	printf("%d\n", diff_min);

	return 0;
}

#endif
