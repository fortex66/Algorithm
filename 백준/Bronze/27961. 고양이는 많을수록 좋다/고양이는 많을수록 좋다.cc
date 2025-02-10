#include<iostream>
using namespace std;

typedef long long ll;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	ll n, cats = 1, magic = 1;
	cin >> n;

	if (n == 0 || n == 1) {
		cout << n;
		return 0;
	}

	while (cats < n) {
		if (cats * 2 <= n) {
			cats *= 2;
			magic++;
		}
		else {
			cats = n;
			magic++;
		}
	}

	cout << magic;

	return 0;
}