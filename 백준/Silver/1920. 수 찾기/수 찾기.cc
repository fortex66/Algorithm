#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n; int m;
	cin >> n;

	vector<int> v1;

	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		v1.push_back(a);
	}

	sort(v1.begin(), v1.end());
	
	cin >> m;

	for (int i = 0; i < m; i++) {
		int a;
		cin >> a;

		int left = 0;
		int right = n - 1;
		bool found = false;

		while (left <= right) {
			int mid = (left + right) / 2;
			if (a > v1[mid]) {
				left = mid + 1;
			}
			else if (a < v1[mid]) {
				right = mid - 1;
			}
			else {
				found = true;
				break;
			}
		}
		
		if (found) cout << 1 << '\n';
		else cout << 0 << '\n';

	}


	return 0;
}