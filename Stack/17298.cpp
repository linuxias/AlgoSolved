/*
* https://www.acmicpc.net/problem/17298
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stack>

using namespace std;

int A[1000005];
stack<int> nge;
int idx = 0;

int main() {
	int tmp;
	int N;
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
		scanf("%d", &A[i]);
	
	for (int i = N - 1; i >= 0; i--) {
		while (!nge.empty() && nge.top() <= A[i])
			nge.pop();

		int tmp = A[i];
		if (nge.empty()) {
			A[i] = - 1;
		}
		else {
			A[i] = nge.top();
		}
		nge.push(tmp);
	}

	for (int i = 0; i < N - 1; i++)
		printf("%d ", A[i]);

	printf("%d\n", A[N - 1]);

	return 0;
}
