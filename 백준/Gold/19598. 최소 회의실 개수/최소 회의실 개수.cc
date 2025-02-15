#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

bool comp(const pair<int,int>& a, const pair<int,int>& b) {
	return a.first < b.first;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	vector<pair<int, int> > metting(N);

	for (int i = 0; i < N; i++) {
		cin >> metting[i].first >> metting[i].second;
	}

	// 회의 시작 시간을 기준으로 오름차순 정렬
	sort(metting.begin(), metting.end(), comp);

	priority_queue<int, vector<int>, greater<int>> pq;

	// 첫 회의를 넣고 시작
	pq.push(metting[0].second);

	// 회의 순회
	for (int i = 1; i < N; i++) {
		if (metting[i].first >= pq.top()) {
			pq.pop();
			pq.push(metting[i].second);
		}
		else {
			pq.push(metting[i].second);
		}
	}

	cout << pq.size();

	return 0;
}