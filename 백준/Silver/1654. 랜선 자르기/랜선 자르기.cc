#include<iostream>
#include<vector>
using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	// 가지고 있는 랜선의 개수 K
	// 필요한 랜선의 개수 N
	ll K, N;
	cin >> K >> N;

	vector<long long> V;
	ll st = 1;
	ll en = 1;
	ll result = 0;
	for (int i = 0; i < K; i++) {
		ll a;
		cin >> a;
		V.push_back(a);
		en = max(en, a);
	}

	while (st <= en) {
		ll mid = (st + en) / 2;
		ll cnt = 0;
		for (int i = 0; i < K; i++) {
			cnt += V[i] / mid;
		}
		if (cnt >= N) {
			result = mid;
			st = mid + 1;
		}
		else {
			en = mid - 1;
		}
	}
	
	cout << result;

}