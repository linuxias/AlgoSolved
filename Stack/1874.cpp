/*
* https://www.acmicpc.net/problem/1874
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int stack[100001]; 
int idx = -1;
char output[500001];
int o_idx = -1;


int main() {
	int N;
	scanf("%d", &N);

	int tmp;
	int cur = 1;
	int max = 1;
	while (N--) {
		scanf("%d", &tmp);

		if (stack[idx] > tmp)
			break;

		while (tmp >= cur) {
			stack[++idx] = cur;
			cur++;
			output[++o_idx] = '+';
			output[++o_idx] = '\n';
		}

		while (stack[idx] >= tmp) {
			--idx;
			output[++o_idx] = '-';
			output[++o_idx] = '\n';
		}
	}

	if (idx >= 0)
		printf("NO\n");
	else
		printf("%s\n", output);

	return 0;
}
