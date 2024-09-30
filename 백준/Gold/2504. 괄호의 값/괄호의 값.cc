#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string str;
	stack<char> s;
	int sum = 0; // 합
	int mul = 1; // 곱

	cin >> str;
	int str_len = str.length();

	for (int i = 0; i < str_len; i++) {
		// '(' 스텍에 push
		if (str[i] == '(') {
			mul *= 2;
			s.push(str[i]);
		}
		// '[' 스텍에 push
		else if (str[i] == '[') {
			mul *= 3;
			s.push(str[i]);
		}
		// ')'
		else if (str[i] == ')') {
			if (s.empty() || s.top() != '(') {
				cout << 0;
				return 0;
			}
			if (str[i - 1] == '(') {
				sum += mul;
			}
			s.pop();
			mul /= 2;
		}
		// ']' 
		else if (str[i] == ']') {
			if (s.empty() || s.top() != '[') {
				cout << 0;
				return 0;
			}
			if (str[i - 1] == '[') {
				sum += mul;
			}
			s.pop();
			mul /= 3;
		}
	}
	if (s.empty()) cout << sum;
	else cout << 0;

	return 0;
}