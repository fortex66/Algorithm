#include <iostream>
#include <stack>
#include <string>
using namespace std;
string str;
stack<char> S;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int result=0;
	cin >> str;
	int len = str.length();

	for (int i = 0; i < len; i++) {
		if (str[i] == '(') S.push(str[i]);
		else {
			if (str[i - 1] == '(') {
				S.pop();
				result += S.size();
			}
			else {
				S.pop();
				result++;
			}
		}
	}

	cout << result;

	return 0;
}