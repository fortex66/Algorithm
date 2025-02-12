#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

struct Beer {
	int prefer;
	int level;
};

bool comp(const Beer& a, const Beer& b) {
	return a.level < b.level;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, M, K, ans = -1;
	cin >> N >> M >> K;

	vector<Beer> beers(K);
	for (int i = 0; i < K; i++) {
		cin >> beers[i].prefer >> beers[i].level;
	}

	// 도수 기준으로 오름차순
	sort(beers.begin(), beers.end(), comp);

	// 오름차순을 위한 형태
	priority_queue<int, vector<int>, greater<int> > pq;
	long long total_prefer = 0;

	// 선호도 및 도수 오름차순
	for (const Beer& b : beers) {
		pq.push(b.prefer);
		total_prefer += b.prefer;

		if (pq.size() > N) {
			total_prefer -= pq.top();
			pq.pop();
		}

		// 선택된 맥주가 N개이고 총 선호도 합이 M 이상일 때
		if (pq.size() == N && total_prefer >= M) {
			ans = b.level;
			break;
		}
	}

	cout << ans;
	return 0;
}