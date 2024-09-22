#include<iostream>
#include<string>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	string s;
	cin >> s;

	char arr[26] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
	int result[26] = {0,};
	for (int i = 0; i < s.size(); i++) {
		for (int j = 0; j < sizeof(arr); j++) {
			if (s[i] == arr[j]) result[j]++;
		}
	}

	for (int i = 0; i < 26; i++) {
		cout << result[i] << ' ';
	}

	return 0;
}