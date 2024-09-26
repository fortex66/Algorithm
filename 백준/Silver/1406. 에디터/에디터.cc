#include <iostream>
#include <list>
#include <string>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string N;
	int M;
	list<char> L;

	cin >> N >> M;
	
	for (char i : N) L.push_back(i);

	auto cursor = L.end();

	for (int i = 0; i < M; i++) {
		char a;
		cin >> a ;
		if (a == 'L') {
			if (cursor != L.begin()) cursor--;
		}
		else if (a == 'D') {
			if (cursor != L.end()) cursor++;
		}
		else if (a == 'B') {
			if (cursor != L.begin()) {
				cursor--;
				cursor = L.erase(cursor);
			}
		}
		else if (a == 'P'){
			char b;
			cin >> ws >> b;
			L.insert(cursor, b);
		}
	}

	for (auto i : L) cout << i;

	return 0;
}