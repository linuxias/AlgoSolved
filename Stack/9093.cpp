/*
* https://www.acmicpc.net/problem/9093
*/ 

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	int N;
	cin >> N;
	cin.ignore();

	while (N--) {
		string input;
		getline(cin, input);

		int start = 0;
		for (int i = 0; i < input.length(); i++) {
			if (input[i] == ' ') {
				reverse(input.begin() + start, input.begin() + i);
				start = i + 1;
			}
		}

		reverse(input.begin() + start, input.end());
		cout << input << endl;
	}
}

#if 0 // C
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

char stack[21];

int main() {
	int N;
	int stack_idx = -1;
	scanf("%d\n", &N);

	for (int i = 0; i < N; i++) {
		char c;
		while ((c = getchar())) {
			if (c == ' ') {
				while (stack_idx >= 0) {
					printf("%c", stack[stack_idx]);
					stack_idx--;
				}
				printf(" ");
			}
			else if (c == '\n') {
				while (stack_idx >= 0) {
					printf("%c", stack[stack_idx]);
					stack_idx--;
				}
				break;
			}
			else {
				stack_idx++;
				stack[stack_idx] = c;
			}
		}
		printf("\n");
	}

	return 0;
}

#endif
