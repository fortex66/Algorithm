#include <iostream>
#include <algorithm>
using namespace std;

bool isused1[50];
bool isused2[50];
bool isused3[50];
int N,cnt;

void func(int cur) {
	if (cur == N) {
		cnt++;
		return;
	}
	// cur : 행 / i : 열
	for (int i = 0; i < N; i++) {
		// 하나라도 true이면 pass
		if (isused1[i] || isused2[i + cur] || isused3[cur - i + N - 1]) continue;
		isused1[i] = 1;
		isused2[i + cur] = 1;
		isused3[cur - i + N - 1] = 1;
		func(cur + 1);
		isused1[i] = 0;
		isused2[i + cur] = 0;
		isused3[cur - i + N - 1] = 0;
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	func(0);
	cout << cnt;
}