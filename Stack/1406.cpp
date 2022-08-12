/*
* https://www.acmicpc.net/problem/1406
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

char front_stack[600001];
int front_top = -1;
char rear_stack[600001];
int rear_top = -1; 

int main() {
	int N;

	scanf("%s", front_stack);
	front_top = strlen(front_stack) - 1;

	scanf("%d", &N);

	char code;
	while (N--) {
		scanf(" %c", &code);
		if (code == 'L' && front_top >= 0) {
			rear_stack[++rear_top] = front_stack[front_top--];
		}
		else if (code == 'D' && rear_top >= 0) {
			front_stack[++front_top] = rear_stack[rear_top--];
		}
		else if (code == 'B' && front_top >= 0) {
			front_top--;

		}
		else if (code == 'P') {
			char c;
			scanf(" %c", &c);
			front_stack[++front_top] = c;
		}
	}

	front_stack[front_top + 1] = '\0';
	printf("%s", front_stack);
	for (int i = rear_top; i >= 0; i--) {
		printf("%c", rear_stack[i]);
	}

	return 0;
}
