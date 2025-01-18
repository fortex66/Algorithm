#include<iostream>
#include<algorithm>
using namespace std;

int arr[100002];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, M;
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + N);

	int en = 0;
	int ans = 0x7fffffff;

	// 배열을 순회하면서 찾기
	for (int st = 0; st < N; st++) {
		while (arr[en] - arr[st] < M && en < N) en++;
		if (en == N) break;
		ans = min(ans, arr[en] - arr[st]);
	}

	cout << ans;

	return 0;
}