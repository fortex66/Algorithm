#include <iostream>
#include <deque>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	deque<int> D;

	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;
		if (str == "push_front") {
			int x;
			cin >> x;
			D.push_front(x);
		}
		else if (str == "push_back") {
			int x;
			cin >> x;
			D.push_back(x);
		}
		else if (str == "pop_front") {
			if (D.empty()) cout << -1 << '\n';
			else {
				cout << D.front() << '\n';
				D.pop_front();
			}
		}
		else if (str == "pop_back") {
			if (D.empty()) cout << -1 << '\n';
			else {
				cout << D.back() << '\n';
				D.pop_back();
			}
		}
		else if (str == "size") cout << D.size() << '\n';
		else if (str == "empty") cout << D.empty() << '\n';
		else if(str=="front"){
			if (D.empty()) cout << -1 << '\n';
			else cout << D.front() << '\n';
		}
		else {
			if (D.empty()) cout << -1 << '\n';
			else cout << D.back() << '\n';
		}
	}

	return 0;
}