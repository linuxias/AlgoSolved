#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <queue>

using namespace std;

#define LEN_MAX 1005

typedef struct pos {
	int x;
	int y;
} pos;

pos cood[4] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
int N, M;
int map[LEN_MAX][LEN_MAX] = {0,};
bool visit[LEN_MAX][LEN_MAX] = { false, };
queue<pos> q;
int cnt = 0;
int maxval = 0;

void find() {
	while(!q.empty()) {
		pos p = q.front();
		q.pop();

		visit[p.x][p.y] = true;

		for (int i = 0; i < 4; i++) {
			int tx = p.x + cood[i].x;
			int ty = p.y + cood[i].y;
			if (tx < 0 || tx >= N || ty < 0 || ty >= M)
				continue;
			if (visit[tx][ty] == true || map[tx][ty] != 0)
				continue;

			map[tx][ty] = map[p.x][p.y] + 1;
			visit[tx][ty] = true;

			maxval = maxval > map[tx][ty] ? maxval : map[tx][ty];
			cnt++;
			q.push(pos{ tx, ty });
		}

	}
}

int main() {
	scanf("%d %d", &M, &N);

	for (int col = 0; col < N; col++) {
		for (int row = 0; row < M; row++) {
			scanf("%d", &map[col][row]);
			if (map[col][row] == 1) {
				q.push(pos{ col, row });
				cnt++;
			}
			else if (map[col][row] == -1) {
				cnt++;
			}
		}
	}

	if (cnt == N * M) {
		printf("0");
		return 0;
	}

	find();

	if (cnt < M * N)
		printf("-1\n");
	else
		printf("%d\n", maxval - 1);

	return 0;
}

