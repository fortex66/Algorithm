#include <iostream>
#include <string>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	
	cin >> N;

	for (int i = 0; i < N; i++) {
		string str1, str2;
		bool answer = true;
		int arr[26] = {};
		cin >> str1 >> str2;

		if (str1.length() != str2.length()) {
			cout << "Impossible\n";
			continue;
		}

		for (int j = 0; j < str1.length(); j++) {
			arr[str1[j] - 'a']++;
		}
		for (int j = 0; j < str2.length(); j++) {
			arr[str2[j] - 'a']--;
		}
		for (int j = 0; j < 26; j++) {
			if (arr[j] != 0) {
				answer = false;
				break;
			}
		}
		cout << (answer  ? "Possible\n" : "Impossible\n");
	}

	return 0;
}