#include <stdio.h>
#include <math.h>

int N;
int row_col_sum[22] = {0,};
int total = 0;
int diff_min = 0x7ffffff;

void find(int idx, int team_total, int val) {
	if (team_total <= N - 1) {
		diff_min = diff_min < abs(val) ? diff_min : abs(val);
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
