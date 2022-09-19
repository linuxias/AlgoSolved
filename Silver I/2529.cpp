/*
* https://www.acmicpc.net/problem/2529
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int N;
bool sign[9] = { false, }; // false > , true <
int res[10] = { 0, };
int min_res[10] = { 0, };
int max_res[10] = { 0, };
bool visit[10] = { false };
int cnt = 0;

void find(int idx) {
	if (idx == N + 1) {
		bool isRight = true;
		for (int i = 0; i < N; i++) {
			if (sign[i] == false) { // >
				if (res[i] < res[i + 1]) {
					isRight = false;
					break;
				}
			}
			else { // <
				if (res[i] > res[i + 1]) {
					isRight = false;
					break;
				}
			}
		}

		if (isRight) {
			if (cnt == 0) {
				for (int i = 0; i <= N; i++) {
					min_res[i] = res[i];
				}
			}
			else {
				for (int i = 0; i <= N; i++) {
					max_res[i] = res[i];
				}
			}
			cnt++;
		}
		return;
	}

	for (int i = 0; i < 10; i++) {
		if (visit[i])
			continue;

		visit[i] = true;
		res[idx] = i;
		find(idx + 1);
		visit[i] = false;
	}
}


int main() {
	char tmp;
	scanf("%d\n", &N);

	for (int i = 0; i < N; i++) {
		scanf(" %c", &tmp);
		sign[i] = tmp == '>' ? false : true;
	}

	find(0);

	for (int i = 0; i <= N; i++)
		printf("%d", max_res[i]);

	printf("\n");

	for (int i = 0; i <= N; i++)
		printf("%d", min_res[i]);
	return 0;
}
