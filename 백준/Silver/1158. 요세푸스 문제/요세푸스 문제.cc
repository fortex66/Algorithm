#include <iostream>
#include <list>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, K;
	cin >> N >> K;

	list<int> L;
	vector<int> result;

	// 리스트에 N만큼 숫자를 넣기
	for (int i = 1; i <= N; i++) {
		L.push_back(i);
	}
	
	auto t = L.begin();
	
	// t의 값을 제거하고 결과 백터에 값을 넣기
	while (!L.empty()) {
		// t를 K-1번 증가
		for (int j = 1; j < K; j++) {
			t++;
			if (t == L.end()) t = L.begin();
		}

		result.push_back(*t);
		t = L.erase(t);

		if (t == L.end()) t = L.begin();
	}

	cout << "<";

	for (int i = 0; i < result.size(); i++) {
		cout << result[i];
		if (i != result.size() - 1) cout << ", ";
	}
	cout << ">";

	return 0;
}