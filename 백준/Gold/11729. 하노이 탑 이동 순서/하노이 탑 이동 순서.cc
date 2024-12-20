#include <iostream>
using namespace std;

void func(int a, int b, int n) {
	if (n == 1) {
		cout << a << ' ' << b << '\n';
		return;
	}
	func(a, 6 - a - b, n - 1); // n-1번째 까지 원판을 a에서 빈칸으로
	cout << a << ' ' << b << '\n'; // a->b 출력
	func(6 - a - b, b, n - 1); // n-1개의 원판을 b로
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int k;
	cin >> k;
	cout << (1 << k) - 1 << '\n';
	func(1, 3, k);
}