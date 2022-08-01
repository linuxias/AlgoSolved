/*
* https://www.acmicpc.net/problem/1316
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

int main() {
	int N;
	int cnt = 0;
	char tmp[101];
	int alpha[26];

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 26; j++)
			alpha[j] = 0;

		scanf("%s", tmp);
		cnt++;
		
		for (int j = 0; j < strlen(tmp); j++) {
			if (alpha[tmp[j] - 'a']) {
				cnt--;
				break;
			}
			while (tmp[j] == tmp[j+1]) j++;
			alpha[tmp[j] - 'a'] = 1;
		}
	}

	printf("%d\n", cnt);
}
