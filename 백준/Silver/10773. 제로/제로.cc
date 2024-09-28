#include <iostream>
#include <stack>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	stack<int> S;

	int K, result=0;
	cin >> K;

	while (K--) {
		int i;
		cin >> i;
		if (i == 0) S.pop();
		else S.push(i);
	}

	while(!S.empty()) {
		result += S.top();
		S.pop();
	}

	cout << result;

	return 0;
}