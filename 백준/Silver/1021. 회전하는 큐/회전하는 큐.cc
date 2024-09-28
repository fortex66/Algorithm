#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, M, answer = 0;
	cin >> N >> M;

	deque<int> DQ;

	for (int i = 1; i <= N; i++) DQ.push_back(i);

	for (int i = 1; i <= M; i++) {
		int x;
		cin >> x;
		// x가 덱의 몇번째에 위치하는지
		int idx = find(DQ.begin(), DQ.end(), x)-DQ.begin();
		while (DQ.front() != x) {
			// 후반부에 위치하면
			if (idx > DQ.size() - idx) {
				DQ.push_front(DQ.back());
				DQ.pop_back();
			}
			// 전반부에 위치하면
			else {
				DQ.push_back(DQ.front());
				DQ.pop_front();
			}
			answer++;
		}
		DQ.pop_front();
	}

	cout << answer;

	return 0;
}