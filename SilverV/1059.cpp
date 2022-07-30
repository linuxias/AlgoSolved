#define _CRT_SECURE_NO_WARNINGS

#include <algorithm>
#include <stdio.h>

int compare(const void* a, const void* b) {
	const int *comp1 = (const int *)a;
	const int* comp2 = (const int*)b;
	return *comp1 - *comp2;
}

int main() {
	int S, n;
	int data[51] = {0,};

	scanf("%d", &S);

	for (int i = 1; i <= S; i++)
		scanf("%d", &data[i]);
	scanf("%d", &n);

	qsort(data, S + 1, sizeof(int), compare);

	int A, B;
	for (int i = 0; i <= S; i++) {
		if (data[i] == n) {
			printf("0\n");
			return 0;
		}
		
		if (data[i] > n) {
			A = data[i - 1];
			B = data[i];
			break;
		}
	}

	int cnt = 0;
	cnt = (n - A) * (B - n) - 1;

	printf("%d\n", cnt);

	return 0;
}
