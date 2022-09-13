/*
* https://www.acmicpc.net/problem/10973
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <algorithm>

using namespace std;

int N;
int input[10001];
int pos[10001];

bool compare(int a, int b) {
	return b < a;
}

void find_pre_permutation() {
	int i;
	int pre_input;

	for (i = N - 2; i >= 0; i--) {
		pre_input = input[i + 1];
		if (input[i] < pre_input)
			continue;
		break;
	}

	if (i < 0) {
		input[0] = -1;
		N = 1;
		return;
	}

	int cur_input = input[i];
	int min_input = 0;
	for (int j = i + 1; j < N; j++) {
		if (cur_input > input[j] && input[j] > min_input)
			min_input = input[j];
	}

	int tmp = input[pos[min_input]];
	input[pos[min_input]] = input[i];
	input[i] = tmp;

	sort(input + i + 1, input + N, compare);
}

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &input[i]);
		pos[input[i]] = i;
	}

	find_pre_permutation();

	for (int i = 0; i < N; i++) {
		printf("%d ", input[i]);
	}
	printf("\n");

	return 0;
}
