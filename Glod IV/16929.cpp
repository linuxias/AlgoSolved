#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define MAX_SIZE 50

int N, M;
char compare_c;
char map[MAX_SIZE][MAX_SIZE];
int visit[MAX_SIZE][MAX_SIZE] = { 0, };
bool is_closed = false;

void find(int x, int y, int px, int py, int len) {
	if (x < 0 || x >= MAX_SIZE || y < 0 || y >= MAX_SIZE || is_closed)
		return;

	if (compare_c != map[x][y])
		return;

	if (visit[x][y] > 0 && visit[px][py] - visit[x][y] >= 3) {
		is_closed = true;
		return;
	}

	if (visit[x][y])
		return;

	visit[x][y] = len;
	find(x + 1, y, x, y,len + 1);
	find(x - 1, y, x, y, len + 1);
	find(x, y + 1, x, y, len + 1);
	find(x, y - 1, x, y, len + 1);
}

int main() {
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++)
		scanf("%s", &map[i]);

	for (int i = 0; i < N && !is_closed; i++) {
		for (int j = 0; j < M && !is_closed; j++) {
			if (visit[i][j])
				continue;
			compare_c = map[i][j];
			visit[i][j] = 1;
			find(i + 1, j, i, j, 2);
			find(i - 1, j, i, j, 2);
			find(i, j + 1, i, j, 2);
			find(i, j - 1, i, j, 2);
		}
	}

	printf("%s\n", is_closed ? "Yes" : "No");

	return 0;
}

