#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, M;
	cin >> N;

	vector<int> V1;
	vector<int> V2;

	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		V1.push_back(a);
	}

	cin >> M;

	for (int i = 0; i < M; i++) {
		int a;
		cin >> a;
		V2.push_back(a);
	}

	sort(V1.begin(), V1.end());

	for (int i = 0; i < M; i++) {
		cout <<( upper_bound(V1.begin(), V1.end(), V2[i]) - lower_bound(V1.begin(), V1.end(), V2[i]) ) << " ";
	}

	return 0;
}