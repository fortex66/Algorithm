#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	vector<int> one(N);
	vector<int> two;

	// 원소 하나의 집합
	for (int i = 0; i < N; i++) {
		cin >> one[i];
	}

	sort(one.begin(), one.end());

	// 원소 2개를 선택하여 더한 집합들
	for (int i = 0; i < N; i++) {
		for (int j = i; j < N; j++) {
			two.push_back(one[i] + one[j]);
		}
	}

	sort(two.begin(), two.end());
	// x + y + z = k
	// x + y 를 two로 구현 => two + z = k
	// k - z 에서 two가 있는지 이진 탐색하면 된다.

	for (int i = N - 1; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			if (binary_search(two.begin(), two.end(), one[i] - one[j])) {
				cout << one[i];
				return 0;
			}
		}
	}
}