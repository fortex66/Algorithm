#include<iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	
	for (int i = 0; i < 3; i++) {
		int front = 0;
		int back = 0;
		for (int j = 0; j < 4; j++) {
			int a;
			cin >> a;
			if (a == 0) front++;
			else back++;
		}
		if (front == 0) cout << 'E' << '\n';
		else if (front == 1) cout << 'A' << '\n';
		else if (front == 2) cout << 'B' << '\n';
		else if (front == 3) cout << 'C' << '\n';
		else cout << 'D' << '\n';
	}
	

	return 0;
}