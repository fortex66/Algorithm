#include <iostream>
using namespace std;

int n, m, x, y, k;
int board[21][21];

int dx[5] = { 0,0,0,-1,1 };
int dy[5] = { 0,1,-1,0,0 };

int dice[7];

void roll_right() {
	int tmp = dice[4];
	dice[4] = dice[5];
	dice[5] = dice[2];
	dice[2] = dice[6];
	dice[6] = tmp;
}

void roll_left() {
	int tmp = dice[2];
	dice[2] = dice[5];
	dice[5] = dice[4];
	dice[4] = dice[6];
	dice[6] = tmp;
}

void roll_up() {
	int tmp = dice[2];
	dice[2] = dice[1];
	dice[1] = dice[4];
	dice[4] = dice[3];
	dice[3] = tmp;
}

void roll_down() {
	int tmp = dice[2];
	dice[2] = dice[3];
	dice[3] = dice[4];
	dice[4] = dice[1];
	dice[1] = tmp;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> x >> y >> k;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}

	// 명령 실행
	while (k--) {
		int command;
		cin >> command;

		int nx = x + dx[command];
		int ny = y + dy[command];

		// 수행할 command 유효성 판단
		if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;

		x = nx;
		y = ny;

		if (command == 1) {
			roll_right();
		}
		else if (command == 2) {
			roll_left();
		}
		else if (command == 3) {
			roll_up();
		}
		else { // command == 4
			roll_down();
		}
		// 윗면 출력
		cout << dice[4] << '\n';

		if (board[x][y] == 0) {
			board[x][y] = dice[2];
		}
		else {
			dice[2] = board[x][y];
			board[x][y] = 0;
		}
	}
}