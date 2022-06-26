/*
* https://www.acmicpc.net/problem/1010
*/

#include <iostream>

using namespace std;

#define ULL unsigned long long

ULL result[31][31] = { 1, };

void comb() {
	for (int i = 0; i < 31; i++) {
		for (int j = 0; j <= i && j < 31; j++) {
			if (j == 0 || i == 0 || i == j) result[i][j] = 1;
			else result[i][j] = result[i - 1][j - 1] + result[i - 1][j];
		}
	}
}

int main()
{
	int testcase;
	ULL N, M;

	comb();

	cin >> testcase;
	for (int t = 0; t < testcase; t++) {
		cin >> N >> M;
		cout << result[M][N] << endl;
	}

	return 0;
}
