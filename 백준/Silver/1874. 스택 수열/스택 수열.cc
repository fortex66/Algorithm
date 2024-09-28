#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	stack<int> S;
	vector<string> R;
	int arr[100001] = {};

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int k;
		cin >> k;
		arr[i] = k;
	}
	
	int idx = 1;
	for(int i = 0; i < n; i++){
		while (idx <= arr[i]) {
			S.push(idx);
			idx++;
			R.push_back("+");
		}
		if (arr[i] == S.top()) {
			S.pop();
			R.push_back("-");
		}
		else {
			cout << "NO\n";
			return 0;
		}

	}

	for (int i = 0; i < R.size(); i++) {
		cout << R[i] << '\n';
	}

	return 0;
}