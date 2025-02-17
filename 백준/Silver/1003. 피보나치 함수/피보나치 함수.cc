#include<iostream>
using namespace std;

int dp0[41], dp1[41];

void fill_dp() {
	// 초기 0과 1의 값 세팅
	dp0[0] = 1; dp1[0] = 0;
	dp1[1] = 0; dp1[1] = 1;
	// 초기 값을 바탕으로 연산
	for (int i = 2; i < 41; i++) {
		dp0[i] = dp0[i - 1] + dp0[i - 2];
		dp1[i] = dp1[i - 1] + dp1[i - 2];
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	fill_dp();

	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		cout << dp0[N] << " " << dp1[N] << '\n';
	}

	return 0;
}