#include <iostream>

using namespace std;

long long recursion(long long a, long long b, long long c) {
	if (b == 1) return a % c;
	long long val = recursion(a, b / 2, c);
	val = val * val % c;
	if (b % 2 == 0) return val;
	return val * a % c;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	long long A, B, C;
	
	cin >> A >> B >> C;

	
	cout << recursion(A, B, C);
	
	return 0;
}