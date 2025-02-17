#include<iostream>
#include<algorithm>
using namespace std;

int arr[10002];
int dist[10001];

bool comp(int a, int b) {
	return a > b;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, K, ans = 0;
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + N);

	for (int i = 1; i < N; i++) {
		dist[i - 1] = arr[i] - arr[i - 1];
	}

	sort(dist, dist + N - 1,comp);

	for (int i = 0; i < K - 1; i++) {
		dist[i] = 0;
	}

	for (int i = 0; i < N - 1; i++) {
		ans += dist[i];
	}

	cout << ans;

	return 0;
}