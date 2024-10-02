#include <iostream>
#include <queue>
using namespace std;

int board[100002];

int N, K;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> K;

	queue<int> Q;

	Q.push(N);
	board[N] = 1;

	while (!Q.empty()) {
		int cur = Q.front();
		if (cur == K) {
			cout << board[cur]-1;
			return 0;
		}
		Q.pop();
		if (cur-1 >= 0 && board[cur - 1] == 0) {
			board[cur - 1] = board[cur] + 1;
			Q.push(cur - 1);
		}
		if (cur + 1 <= 100000 && board[cur + 1] == 0) {
			board[cur + 1] = board[cur] + 1;
			Q.push(cur + 1);
		}
		if (cur*2 <= 100000 && board[2 * cur] == 0) {
			board[2 * cur] = board[cur] + 1;
			Q.push(2 * cur);
		}
	}
}