#include<iostream>
#include<algorithm>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, ans = 0;
	int arr[1001] = { 0 };
	int dp[1001] = { 0 };
	cin >> N;

	fill(dp, dp + N, 1);

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < i; j++) {
			if (arr[j] < arr[i]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
	}

	for (int i = 0; i < N; i++) {
		ans = max(dp[i], ans);
	}

	cout << ans;
}