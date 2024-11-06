#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	vector<long long> v;

	cin >> n;

	for (int i = 0; i < n; i++) {
		long long card;
		cin >> card;
		v.push_back(card);
	}

	sort(v.begin(), v.end());

	long long mxval = -(111 << 62)-1;
	int cnt = 0, mxcnt = 0;

	for (int i = 0; i < n; i++) {
		if (i == 0 || v[i - 1] == v[i]) cnt++;
		else {
			if (cnt > mxcnt) {
				mxcnt = cnt;
				mxval = v[i - 1];
			}
			cnt = 1;
		}
	}
	if (cnt > mxcnt) mxval = v[n - 1];
	cout << mxval;
}