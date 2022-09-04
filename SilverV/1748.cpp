/*
* https://www.acmicpc.net/problem/1748
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <algorithm>

using namespace std;

int main() {
	int N, ans = 0;

	scanf("%d", &N);

	for (int i = 1; i <= N; i *= 10) {
		ans += N - i + 1;
		printf("%d %d\n", i, ans);
	}

	printf("%d\n", ans);
	return 0;
}
