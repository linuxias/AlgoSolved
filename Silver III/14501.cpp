/*
* https://www.acmicpc.net/problem/14501
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int N;
int day[16] = { 0, };
int pay[16] = { 0, };
int maxpay = 0;

void find(int idx, int sum) {
	if (idx > N)
		return;

	maxpay = maxpay > sum ? maxpay : sum;
	for (int i = idx + day[idx]; i < N; i++) {
		if (i + day[i] > N)
			continue;
		find(i, sum + pay[i]);
	}
}

int main() {
	scanf("%d", &N);

	for (int i = 0; i < 16; i++) {
		day[i] = 16;
	}

	for (int i = 0; i < N; i++) {
		scanf("%d %d", &day[i], &pay[i]);
	}

	for (int i = 0; i < N; i++) {
		if (i + day[i] > N)
			continue;
		find(i, pay[i]);
	}

	printf("%d\n", maxpay);
}
