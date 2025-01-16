#include<iostream>
#include<vector>
using namespace std;

typedef long long ll;

// 블루레이 크기가 mid일 때 모든 강의를 M개의 블루레이에 녹화할 수 있는지 확인하는 함수
bool divLec(const vector<int>& V, int M, ll mid) {
	int cnt = 1;   // 필요한 블루레이 개수 최소 1
	ll total = 0;  // 현재 블루레이에 들어있는 강의의 총 길이

	for (int lec : V) {
		if (total + lec > mid) {
			cnt++;		  // 새로운 블루레이
			total = lec;  // 새로운 블루레이에 강의 추가
			if (cnt > M) return false; // M개 초과하면 불가능
		}
		else total += lec; //현재 블루레이에 강의를 추가
	}
	return true;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	// N개의 강의가 들어감, M개의 블루레이
	int N, M;
	cin >> N >> M;
	vector<int> V(N);

	for (int i = 0; i < N; i++) cin >> V[i];

	ll st = V[0];
	ll en = 0;
	for (int i = 0; i < N; i++) {
		if (V[i] > st) st = V[i];
		en += V[i];
	}

	ll ans = en;

	while (st <= en) {
		ll mid = (st + en) / 2;
		
		if (divLec(V, M, mid)) {
			ans = mid;
			en = mid - 1;
		}
		else st = mid + 1;
	}

	cout << ans;

	return 0;
}