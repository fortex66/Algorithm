#include <iostream>
using namespace std;

int N, M;
int arr[10];

void func(int cur) {
	if (cur == M) {
		for (int i = 0; i < M; i++) {
			cout << arr[i] << ' ';
		}
		cout << '\n';
		return;
	}
	for (int i = 1; i <= N; i++) {
		arr[cur] = i;
		func(cur + 1);
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	func(0);
}