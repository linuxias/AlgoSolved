/*
* https://www.acmicpc.net/problem/9093
*/ 
#if 0
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

#elif 1 // C
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

char input[1001] = {0};

void reverse(int start, int end) {
	int tmp;
	while (start < end) {
		tmp = input[start];
		input[start] = input[end];
		input[end] = tmp;
		start++; end--;
	}
}

int main() {
	int N;
	scanf("%d\n", &N);

	while(N--) {
		fgets(input, sizeof(input), stdin);

		int start = 0;
		for (int i = 0; i < strlen(input); i++) {
			if (input[i] == ' ') {
				reverse(start, i - 1);
				start = i + 1;
			}
		}

		reverse(start, strlen(input) - 2);
		printf("%s", input);
	}

	return 0;
}

#endif
