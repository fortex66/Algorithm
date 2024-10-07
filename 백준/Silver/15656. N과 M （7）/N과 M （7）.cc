#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int ans[10];
int arr[10]; // 1 7 8 9
int n, m;

void func(int k) {
	if (k == m) {
		for (int i = 0; i < m; i++)
			cout << arr[ans[i]] << ' ';
		cout << '\n';
		return;
	}
	for (int i = 0; i < n; i++) {
		ans[k] = i;
		func(k + 1);
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	func(0);
}