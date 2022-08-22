/*
* https://www.acmicpc.net/problem/1918 
*/

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
	stack<char> exp;
	string input;
	string res = "";

	cin >> input;
	
	for (char c : input) {
		if ('A' <= c && c <= 'Z') {
			res += c;
		}
		else {
			if (exp.empty()) {
				exp.push(c);
			}
			else if (c == '(') {
				exp.push(c);
			}
			else if (c == ')') {
				while (!exp.empty()) {
					if (exp.top() != '(') {
						res += exp.top();
						exp.pop();
					}
					else {
						exp.pop();
						break;
					}
				}
			}
			else if (c == '*' || c == '/') {
				while (!exp.empty() && (exp.top() == '*' || exp.top() == '/')) {
					res += exp.top();
					exp.pop();
				}
				exp.push(c);
			}
			else if (c == '+' || c == '-') {
				while (!exp.empty()) {
					if (exp.top() == '(') {
						break;
					} else {
						res += exp.top();
						exp.pop();
					}
				}
				exp.push(c);
			}
		}
	}

	while (!exp.empty()) {
		res += exp.top();
		exp.pop();
	}

	cout << res;

	return 0;
}
