/*
* https://www.acmicpc.net/problem/3085
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <algorithm>

using namespace std;

int ret = 0;
char map[55][55] = { 0, };

void  max_len(int N, int x, int y) {
	if (x >= N || y >= N)
		return;

	int len = 1;
	char ch = map[x][y];

	for (int i = x + 1; map[i][y] == ch && i < N; i++) len++;
	for (int i = x - 1; map[i][y] == ch && i >= 0; i--) len++;

	ret = len > ret ? len : ret;

	len = 1;
	for (int i = y + 1; map[x][i] == ch && i < N; i++) len++;
	for (int i = y - 1; map[x][i] == ch && i >= 0; i--) len++;

	ret = len > ret ? len : ret;
}

void swap(char* a, char* b)
{
	char tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

int main() {
	int N;
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
		scanf("%s", map[i]);

	for (int i = 0; i < N; i++) {
		int len;
		for (int j = 0; j < N; j++) {
			swap(&map[i][j], &map[i + 1][j]);
			max_len(N, i, j);
			max_len(N, i + 1, j);
			swap(&map[i][j], &map[i + 1][j]);

			swap(&map[i][j], &map[i][j + 1]);
			max_len(N, i, j);
			max_len(N, i, j + 1);
			swap(&map[i][j], &map[i][j + 1]);
		}
	}

	printf("%d\n", ret);

	return 0;
}
