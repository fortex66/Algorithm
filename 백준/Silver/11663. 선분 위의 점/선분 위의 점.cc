#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, M;
	cin >> N >> M;
	vector<int> V;

	for (int i = 0; i < N; i++) {
		int p;
		cin >> p;
		V.push_back(p);
	}

	sort(V.begin(), V.end());

	for (int i = 0; i < M; i++) {
		int st = 0;
		int en = 0;
		int ans = 0;
		cin >> st >> en;
		
		cout << (upper_bound(V.begin(), V.end(), en) - V.begin()) - (lower_bound(V.begin(), V.end(), st) - V.begin()) << '\n';
	}
}