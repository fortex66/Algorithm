#include <iostream>
#include <deque>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;

	while (T--) {
		string cmd, input;
		int n;
		cin >> cmd >> n >> input;

		deque<int> DQ;
		string num_str = "";

		for (char ch : input) {
			if (isdigit(ch)) {
				num_str += ch;
			}
			else if (!num_str.empty()) {
				DQ.push_back(stoi(num_str));
				num_str = "";
			}
		}

		bool rev = false;
		bool err = false;

		for (char c : cmd) {
			if (c == 'R') {
				rev = !rev;
			}
			else if (c == 'D') {
				if (DQ.empty()) {
					err = true;
					break;
				}
				if (rev) {
					DQ.pop_back();
				}
				else {
					DQ.pop_front();
				}
			}
		}

		if (err) {
			cout << "error\n";
		}
		else {
			cout << '[';
			if (rev) {
				for (int i = DQ.size() - 1; i >= 0; i-- ) {
					cout << DQ[i];
					if (i != 0) cout << ',';
				}
			}
			else {
				for (int i = 0; i < DQ.size(); i++) {
					cout << DQ[i];
					if (i != DQ.size() -1) cout << ',';
				}
			}
			cout << "]\n";
		}
	}

	return 0;
}