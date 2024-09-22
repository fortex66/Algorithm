#include<iostream>
#include<string>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string s;
	cin >> s;

	
	int result[26] = {0,};

	for (int i = 0; i < s.size(); i++) {
		result[s[i] - 'a']++;
	}

	for (int i = 0; i < 26; i++) {
		cout << result[i] << ' ';
	}

	return 0;
}