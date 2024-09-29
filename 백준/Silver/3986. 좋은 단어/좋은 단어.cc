#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, result=0;
	cin >> N;

	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;
		stack<char> S;
		for (char c : str) {
			if (!S.empty() && S.top() == c) S.pop();
			else if (!S.empty() && S.top() != c) S.push(c);
			else if (S.empty()) S.push(c);
			else break;
		}
		if (S.empty()) result++;
	}

	cout << result;

	return 0;
}