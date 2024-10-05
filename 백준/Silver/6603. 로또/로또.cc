#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	while (1) {
		int k;
		cin >> k;
		if (k == 0) return 0;
		vector<int> a;
		vector<int> b;
		// a에 입력값 집어넣기
		for (int i = 0; i < k; i++) {
			int x;
			cin >> x;
			a.push_back(x);
		}
		// k개 중 6개 고르기 0,0,0,0,0,0 만들기
		for (int i = 0; i < k; i++) {
			b.push_back(i < 6 ? 0 : 1);
		}
		// 조합
		do {
			for (int i = 0; i < k; i++) {
				if (b[i] == 0) cout << a[i] << ' ';
			}
			cout << '\n';
		} while (next_permutation(b.begin(), b.end()));
        cout << '\n';
	}
}