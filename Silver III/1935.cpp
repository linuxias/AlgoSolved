/*
* https://www.acmicpc.net/problem/1935
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

double val[26] = { 0, };
double stack[101] = { 0, };
int idx = 0;

double calc(double A, double B, char c) {
	if (c == '+')
		return A + B;
	else if (c == '*')
		return A * B;
	else if (c == '-')
		return A - B;
	else
		return A / B;
}

int main() {
	int N;
	char func[101];
	double ans = 0;

	scanf("%d", &N);
	scanf("%s", func);

	for (int i = 0; i < N; i++)
		scanf("%lf", &val[i]);

	for (int i = 0; i < strlen(func); i++) {
		if ('A' <= func[i] && func[i] <= 'Z') {
			stack[idx++] = val[func[i] - 'A'];
		} else {
			double A = stack[--idx];
			double B = stack[--idx];

			stack[idx++] = calc(B, A, func[i]);;
		}
	}

	printf("%.2lf\n", stack[0]);

	return 0;
}
