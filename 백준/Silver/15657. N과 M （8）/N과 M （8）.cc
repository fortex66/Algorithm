#include <iostream>
#include <algorithm>
using namespace std;

int ans[10];
int arr[10];
int n, m;

void func(int k,int start) {
	if (k == m) {
		for (int i = 0; i < m; i++)
			cout << ans[i] << ' ';
		cout << '\n';
		return;
	}
	for (int i = start; i < n; i++) {
		ans[k] = arr[i];
		func(k + 1,i);
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
	func(0,0);
}