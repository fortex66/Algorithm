#include <iostream>
#include <stack>

using namespace std;

int n, m; // 입력
int arr[10]; // 수열을 담을 배열
bool isused[10]; // 특정 수가 쓰였는지 true or false로 나타내기 위함

void func(int k) {
	// m개를 모두 선택 했다면
	if (k == m) {
		for (int i = 0; i < m; i++) {
			cout << arr[i] << ' ';
		}
		cout << '\n';
		return;
	}
	// 1~n까지 확인하며 아직 쓰이지 않은 수를 찾아내기
	for (int i = 1; i <= n; i++) {
		if (!isused[i]) {
			arr[k] = i;
			isused[i] = 1;
			func(k + 1);
			isused[i] = 0; // return에서 이쪽으로 옴
		}
	}
}


int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	func(0);
}