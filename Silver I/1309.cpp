/*
* https://www.acmicpc.net/problem/1309
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#define ULL unsigned long long

// 0 - OX, 1 - XO, 2 - XX
int main() {
	ULL x = 1;
	ULL y = 1;
	ULL z = 1;
	int tmp;
	scanf("%d", &tmp);

	for (int i = 2; i <= tmp; i++) {

		ULL tmp_x = (y + z) % 9901;
		ULL tmp_y = (x + z) % 9901;
		ULL tmp_z = (((x + y) % 9901) + z) % 9901;

		x = tmp_x;
		y = tmp_y;
		z = tmp_z;
	}

	ULL res = (((x + y) % 9901) + z) % 9901;

	printf("%llu", res);

	return 0;
}
