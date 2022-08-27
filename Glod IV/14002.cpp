/*
* https://www.acmicpc.net/problem/14002
*/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

static int max_len = 1;
static int max_idx = 0;
static int data[1001] = { 0, };
static int len[1001] = { 0, };
static int history[1001] = { 0, };

int main() {
	int N;
	scanf("%d", &N);

	int tmp;
	for (int i = 0; i < N; i++) {
		scanf("%d", &data[i]);
		len[i] = 1;
		for (int j = i; j >= 0; j--) {
			if (data[i] > data[j] && len[i] <= len[j]) {
				len[i] = len[j] + 1;
				history[i] = j;
			}
			if (len[i] > max_len) {
				max_len = len[i];
				max_idx = i;
			}
		}
	}

	printf("%d\n", max_len);
	int print_arr[1001];
	
	for (int i = max_len - 1; i >=0 ; i--) {
		print_arr[i] = data[max_idx];
		max_idx = history[max_idx];
	}

	for (int i = 0; i < max_len; i++)
		printf("%d ", print_arr[i]);

	return 0;
}
