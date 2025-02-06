#include<iostream>

using namespace std;

int board[19][19];

// 우측, 하단, 우측 대각선 아래, 우측 대각선 위
int dx[4] = { -1, 0, 1, 1 };
int dy[4] = { 1, 1, 1, 0 };

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	// 보드 입력
	for (int i = 0; i < 19; i++) {
		for (int j = 0; j < 19; j++) {
			cin >> board[i][j];
		}
	}

	// 보드 탐색
	for (int i = 0; i < 19; i++) {
		for (int j = 0; j < 19; j++) {
			// 돌이 있을 때
			if (board[i][j] != 0) {
				for (int dir = 0; dir < 4; dir++) {
					int px = i - dx[dir];
					int py = j - dy[dir];
					// 이전 칸과 같은 같은 바둑돌이면 시작점 X
					if (px >= 0 && px < 19 && py >= 0 && py < 19 && board[px][py] == board[i][j]) continue;

					int cnt = 1;
					int nx = i + dx[dir];
					int ny = j + dy[dir];

					// 오목 탐색
					while (nx >= 0 && nx < 19 && ny >= 0 && ny < 19 && board[nx][ny] == board[i][j]) {
						cnt++;
						nx += dx[dir];
						ny += dy[dir];
					}

					if (cnt == 5) {
						cout << board[i][j] << '\n';
						cout << i + 1 << " " << j + 1;
						return 0;
					}
				}
			}
		}
	}

	cout << 0;

	return 0;
}