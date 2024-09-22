#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, cnt=1;
	cin >> n;

	int arr[10] = { 0, };

	while (n>0) {
		int digit = n % 10;
		if (digit == 6 || digit == 9) arr[9]++; 
		else arr[digit]++;
		n /= 10;
	}

	arr[9] = (arr[9] + 1) / 2;

	for (int i = 0; i < 10; i++) {
		if (arr[i] > cnt) cnt = arr[i];
	}

	cout << cnt;

	return 0;
}