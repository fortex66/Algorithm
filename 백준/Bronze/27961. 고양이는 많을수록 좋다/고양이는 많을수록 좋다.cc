#include<iostream>
using namespace std;

typedef long long ll;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	ll n;
	cin >> n;

	ll cats = 0;
	int magic = 0;

	bool first = true;

	while (1) {
		if (n == cats) {
			cout << magic;
			return 0;
		}

		if (first) {
			cats++;
			magic++;
			first = false;
		}

		if (n == 1) {
			cout << magic;
			return 0;
		}
		
		if (cats * 2 <= n) {
			cats *= 2;
			magic++;
		}
		else if (cats * 2 > n) {
			cats = n;
			magic++;
		}
	}

	return 0;
}