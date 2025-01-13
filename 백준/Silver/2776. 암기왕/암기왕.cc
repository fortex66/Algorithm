#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;

	while (T--) {
		int N, M;
		vector<int> V; // 수첩1 백터

		// 수첩1 백터에 입력
		cin >> N;
		for (int i = 0; i < N; i++) {
			int a;
			cin >> a;
			V.push_back(a);
		}

		// binary_search() STL을 사용하기 위해 정렬
		sort(V.begin(), V.end());

		// 수첩2의 내용을 V(수첩1)에서 찾기
		cin >> M;
		for (int i = 0; i < M; i++) {
			int a;
			cin >> a;
			if (binary_search(V.begin(), V.end(), a)) cout << 1 << '\n';
			else cout << 0 << '\n';
		}
	}
}