#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool comp(const string& a, const string& b) {
	// 길이가 짧은 것
	if (a.length() != b.length()) {
		return a.length() < b.length();
	}

	int num1=0, num2=0;
	
	for (char c1 : a) {
		if (c1 >= '0' && c1 <= '9') {
			num1 += c1-'0';
		}
	}
	for (char c2 : b) {
		if (c2 >= '0' && c2 <= '9') {
			num2 += c2-'0';
		}
	}
	// 길이가 같으면 숫자만 더해서 작은 것
	if (num1 != num2) {
		return num1 < num2;
	}
	
	return a < b;
}
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	vector<string> serials;

	cin >> n;

	for (int i = 0; i < n; i++) {
		string a;
		cin >> a;
		serials.push_back(a);
	}

	sort(serials.begin(), serials.end(), comp);
	
	for (int i = 0; i < n; i++) {
		cout << serials[i] << '\n';
	}
}