/*
* https://www.acmicpc.net/problem/14391
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int map[4][4];

int main() {
	int N, M; 
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			scanf("%1d", &map[i][j]);

	int result = 0;
	for (int i = 0; i < 1 << (N*M); i++) {
		int sum = 0;
		for (int row = 0; row < N; row++) {
			int row_sum = 0;
			for (int col = 0; col < M; col++) {
				int idx = row * M + col;
				if ((i & (1 << idx)) != 0) {
					row_sum = row_sum * 10 + map[row][col];
				}
				else {
					sum += row_sum;
					row_sum = 0;
				}
			}
			sum += row_sum;
		}

		for (int col = 0; col < M; col++) {
			int col_sum = 0;
			for (int row = 0; row < N; row++) {
				int idx = row * M + col;
				if ((i & (1 << idx)) == 0) {
					col_sum = col_sum * 10 + map[row][col];
				}
				else {
					sum += col_sum;
					col_sum = 0;
				}
			}
			sum += col_sum;
		}

		result = result > sum ? result : sum;
	}

	printf("%d\n", result);

	return 0;
}
