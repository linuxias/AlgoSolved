/*
* https://www.acmicpc.net/problem/14500
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

typedef struct {
	int dx[4];
	int dy[4];
} Poly;

Poly poly[4] = {
	{ // 세로 막대기
		{0, 0, 0, 1},
		{0, 1, 2, 1}
	},
	{ // 가로 막대기
		{0, 1, 2, 1},
		{0, 0, 0, 1}
	},
	{
		{0, 0, 0, -1},
		{0, 1, 2, 1}
	},
	{
		{ 0, -1, 0, 1},
		{ 0, 1, 1, 1 }
	}
};

int N, M;
int ans = 0;
int map[503][503] = {0,};
bool visit[503][503] = {false,};
int dx[4] = { 0 , 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

void find(int x, int y, int idx, int sum) {
	if (x <= 0 || y <= 0 || x > N || y > M)
		return;

	if (visit[x][y] == true)
		return;

	if (idx == 3) {
		if (ans < (sum + map[x][y]))
			ans = (sum + map[x][y]);
		return;
	}

	visit[x][y] = true;
	for (int j = 0; j < 4; j++)
		find(x + dx[j], y + dy[j], idx + 1, sum + map[x][y]);
	visit[x][y] = false;
}

void calc_sum(int x, int y) {
	find(x, y, 0, 0);

	for (int i = 0; i < 4; i++) {
		Poly tmp = poly[i];

		int sum = 0;
		for (int d = 0; d < 4; d++) {
			sum += map[x + tmp.dx[d]][y + tmp.dy[d]];
		}
		if (ans < sum)
			ans = sum;
	}
}

int main() {
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			calc_sum(i, j);
		}
	}

	printf("%d\n", ans);

	return 0;
}
