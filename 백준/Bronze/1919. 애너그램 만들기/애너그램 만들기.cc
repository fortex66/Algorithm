#include <iostream>
#include <string>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string str1, str2;
	int count=0;
	int arr1[26] = {};
	int arr2[26] = {};
	cin >> str1 >> str2;

	for (int i = 0; i < str1.length(); i++) {
		arr1[str1[i] - 'a']++;
	}
	for (int i = 0; i < str2.length(); i++) {
		arr2[str2[i] - 'a']++;
	}
	for (int i = 0; i < 26; i++){
		if (arr1[i] > 0 && arr2[i] > 0) {
			if (arr1[i] >= arr2[i]) count += arr2[i];
			else count += arr1[i];
		}
	}
	cout << (str1.length() + str2.length()) - count*2;
	return 0;
}