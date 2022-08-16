/*
* https://www.acmicpc.net/problem/17298
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stack>

using namespace std;

stack<int> A;
stack<int> res;
int out[1000005];
int idx = 0;

int main() {
	int tmp;
	int N;
	scanf("%d", &N);

	while (N--) {
		scanf("%d", &tmp);
		A.push(tmp);
	}
	out[idx++] = -1;
	res.push(A.top());
	A.pop();

	while (!A.empty()) {
		if (res.empty()) {
			out[idx++] = -1;
			res.push(A.top());
			A.pop();
			continue;
		}

		if (A.top() < res.top()) {
			out[idx++] = res.top();
			res.push(A.top());
			A.pop();
		}
		else {
			if (res.empty() || A.empty())
				break;
			while (res.size() != 0 && res.top() <= A.top()) {
				res.pop();
			}
		}
	}

	for (int i = idx - 1; i > 0; i--) {
		printf("%d ", out[i]);
	}

	printf("%d\n", out[0]);

	return 0;
}
