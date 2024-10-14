#include <iostream>
#include <string>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n, ans = 0;
	char num[101];

	cin >> n;

	for (int i = 0; i < n; i++) {
		char a;
		cin >> a;
		num[i] = a;
	}

	for (int i = 0; i < n; i++) {
		int k = num[i] - '0';
		ans += k;
	}

	cout << ans;
	

	return 0;
}