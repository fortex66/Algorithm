#include <iostream>
#include <stack>
#include <algorithm>
#include <string>
using namespace std;
#define X first
#define Y second

int n = 5, m = 8;
int board[5][8];

int k, num, dir;
int dx[2] = { -1,1 };


void rotate(int x, int y) {
	if (y == 1) {
		int tmp = board[x][7];
		for (int i = 7; i > 0; i--) {
			board[x][i] = board[x][i - 1];
		}
		board[x][0] = tmp;
	}
	else {
		int tmp = board[x][0];
		for (int i = 0; i < 7; i++) {
			board[x][i] = board[x][i + 1];
		}
		board[x][7] = tmp;
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	for (int i = 1; i < n; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < m; j++) {
			board[i][j] = str[j] - '0';
		}
	}

	cin >> k;

	while (k--) {
		stack<pair<int, int> > wheel;
		bool visited[5] = {false};
		cin >> num >> dir;

		wheel.push({ num,dir });
		visited[num] = true;

		while(!wheel.empty()) {
			auto cur = wheel.top();
			wheel.pop();
			int curNum = cur.X;
			int curDir = cur.Y;

			// 왼쪽 기어 검사
			if (curNum > 1 && !visited[curNum - 1]) {
				if (board[curNum][6] != board[curNum - 1][2]) {
					wheel.push({ curNum - 1,-curDir });
					visited[curNum - 1] = true;
				}
			}

			// 오른쪽 기어 검사
			if (curNum < 4 && !visited[curNum + 1]) {
				if (board[curNum][2] != board[curNum + 1][6]) {
					wheel.push({ curNum + 1,-curDir });
					visited[curNum + 1] = true;
				}
			}
			rotate(curNum, curDir);
		}
	}

	int score = 0;
	if (board[1][0] == 1) score++;
	if (board[2][0] == 1) score += 2;
	if (board[3][0] == 1) score += 4;
	if (board[4][0] == 1) score += 8;

	cout << score;
}