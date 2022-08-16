/*
* https://www.acmicpc.net/problem/17413
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

static char str[100005];
static char tmp[100005] = { '\0' };

int main() {
	int tmp_idx = 0;
	bool is_opened = false;
	fgets(str, sizeof(str), stdin);

	for (int i = 0; i < strlen(str) - 1; i++) {
		if (str[i] == ' ') {
			printf(" ");
			continue;
		}

		if (str[i] == '<') {
			while (str[i] != '>')
				printf("%c", str[i++]);
			printf("%c", str[i]);
		}
		else {
			while (1) {
				tmp[tmp_idx++] = str[i];
				if (str[i + 1] == ' ' || str[i + 1] == '<' || i + 2 == strlen(str)) {
					while (--tmp_idx >= 0)
						printf("%c", tmp[tmp_idx]);
					tmp_idx = 0;
					break;
				}
				i++;
			}
		}
	}

	return 0;
}
