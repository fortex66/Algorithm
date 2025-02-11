#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int arr[100002];

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + n);

	int max_weight = 0;
	for (int i = 0; i < n; i++) {
		int weight = arr[i] * (n - i);
		if (weight > max_weight) {
			max_weight = weight;
		}
	}

	cout << max_weight;

	return 0;
}