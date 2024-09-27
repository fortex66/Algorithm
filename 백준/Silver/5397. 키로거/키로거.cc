#include <iostream>
#include <list>
#include <string>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		list<char> L;
		string str;
		cin >> str;

		auto cursor = L.begin();

		for (char j : str) {
			if (j == '<') {
				if (cursor != L.begin()) cursor--;
			}
			else if (j == '>') {
				if (cursor != L.end()) cursor++;
			}
			else if (j == '-') {
				if (cursor != L.begin()) {
					cursor--;
					cursor = L.erase(cursor);
				}
			}
			else L.insert(cursor, j);
		}

		for (char j : L) cout << j;
		cout << '\n';
	}

	return 0;
}