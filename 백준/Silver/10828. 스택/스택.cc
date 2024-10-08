#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	stack<int> S;
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;
		if (str == "push") {
			int X;
			cin >> X;
			S.push(X);
		}
		else if (str == "top") {
			if (S.empty()) cout << -1 << '\n';
			else cout << S.top() << '\n';
		}
		else if (str == "size") cout << S.size() << '\n';
		else if (str == "empty") cout << S.empty() << '\n';
		else {
			if (S.empty()) cout << -1 << '\n';
			else {
				cout << S.top() << '\n';
				S.pop();
			}
		}
	}

	return 0;
}