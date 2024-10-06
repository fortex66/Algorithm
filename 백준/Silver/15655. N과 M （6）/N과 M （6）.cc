#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M;
int arr[10];
bool isused[10];
vector<int> V;

void func(int k) {
	if (k == M) {
		for (int i = 0; i < M; i++) {
			cout << arr[i] << ' ';
		}
		cout << '\n';
		return;
	}
	int x = 0;
	if (k != 0) {
		x = find(V.begin(), V.end(), arr[k - 1]) - V.begin() + 1;
	}
	for (int i = x; i < N; i++) {
		if (!isused[i]) {
			arr[k] = V[i];
			isused[i] = 1;
			func(k + 1);
			isused[i] = 0;
		}
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		int x;
		cin >> x;
		V.push_back(x);
	}
	sort(V.begin(), V.end());
	func(0);
}