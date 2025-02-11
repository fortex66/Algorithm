#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, ans=0;
	cin >> n;

	vector<int> v(n,0);

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	sort(v.begin(), v.end());

	int prep = 0;
	for (int i = 0; i < n; i++) {
		prep += v[i];
		ans += prep;
	}

	cout << ans;

	return 0;
}