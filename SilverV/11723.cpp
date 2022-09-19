/*
* https://www.acmicpc.net/problem/11723
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

int M;
int S = 0;
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int input;
	string cmd;
	cin >> M;

	while (M--) {
		cin >> cmd;

		if (cmd.compare("add") == 0) {
			cin >> input;
			S = (S | (0x01 << (input - 1)));
		}
		else if (cmd.compare("remove") == 0) {
			cin >> input;
			S = (S & ~(0x01 << (input - 1)));
		}
		else if (cmd.compare("check") == 0) {
			cin >> input;
			bool res = (S & (0x01 << (input - 1))) > 0;
			cout << res << "\n";
		}
		else if (cmd.compare("toggle") == 0) {
			cin >> input;
			S ^= (0x01 << (input - 1));
		}
		else if (cmd.compare("all") == 0) {
			S = 0xFFFFF;
		}
		else if (cmd.compare("empty") == 0) {
			S = 0;
		}
	}

	return 0;
}
