#include <iostream>
#include <stack>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	
	
	while (1) {
		string str;
		getline(cin, str);
		if (str == ".") break;

		stack<char> S;

		bool balance = true;

		for (char c : str) {
			if (c == '(' || c == '[') S.push(c);
			else if (c == ']') {
				if (!S.empty() && S.top() == '[') S.pop();
				else {
					balance = false;
					break;
				}
			}
			else if (c == ')') {
				if (!S.empty() && S.top() == '(') S.pop();
				else {
					balance = false;
					break;
				}
			}
		
		}

		if (!S.empty()) balance = false;

		if (balance) cout << "yes\n";
		else cout << "no\n";
	}
	return 0;
}