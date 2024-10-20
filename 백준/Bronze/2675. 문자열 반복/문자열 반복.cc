#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t; // 테스트 케이스 (1 ≤ t ≤ 1,000)
	
	cin >> t;

	while (t--) {
		int r; // 반복 횟수 (1 ≤ r ≤ 8)
		string s;

		cin >> r >> s;

		for (int i = 0; i < s.length(); i++) {
			for (int j = 0; j < r; j++) {
				cout << s[i];
			}
		}
		cout << '\n';
	}

	return 0;
}