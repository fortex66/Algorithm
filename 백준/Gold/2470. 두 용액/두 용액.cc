#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;

pair<ll, ll>find_closet_zero(int N, vector<ll>& arr) {
	sort(arr.begin(), arr.end());

	ll min_sum = 2000000001;
	pair<ll, ll> result = { arr[0], arr[1] };

	for (int i = 0; i < N; i++) {
		ll target = -arr[i];
		int j = lower_bound(arr.begin(), arr.end(), target) - arr.begin();

		if (j < N && i != j) {
			ll current_sum = abs(arr[i] + arr[j]);
			if (current_sum < min_sum) {
				min_sum = current_sum;
				result = { arr[i], arr[j] };
			}
		}

		if (j - 1 >= 0 && i != (j - 1)) {
			ll current_sum = abs(arr[i] + arr[j - 1]);
			if (current_sum < min_sum) {
				min_sum = current_sum;
				result = { arr[i], arr[j - 1] };
			}
		}
	}
	if (result.first > result.second) {
		swap(result.first, result.second);
	}
	return result;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int N;
	cin >> N;
	vector<ll> arr(N);
	for (int i = 0; i < N; i++) cin >> arr[i];

	pair<ll, ll> ans = find_closet_zero(N, arr);
	cout << ans.first << " " << ans.second;

	return 0;
}