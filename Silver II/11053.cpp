/*
* https://www.acmicpc.net/problem/11053
*/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

static int max_len = 0;
static int data[1001] = { 0,};
static int len[1001] = { 0, };

int main() {
	int N;
	scanf("%d", &N);

	int tmp;
	for (int i = 0; i < N; i++) {
		scanf("%d", &data[i]);
		len[i] = 1;
		for (int j = 0; j <= i; j++) {
			if (data[i] > data[j] && len[i] <= len[j])
				len[i] = len[j] + 1;
			if (len[i] > max_len)
				max_len = len[i];
		}
	}

	printf("%d\n", max_len);

	return 0;
}
