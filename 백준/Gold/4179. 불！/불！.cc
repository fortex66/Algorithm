#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;

#define X first
#define Y second

string board[1002];
int f_dist[1002][1002];
int j_dist[1002][1002];

int R, C;

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> R >> C;
	
	for (int i = 0; i < R; i++) {
		cin >> board[i];
	}

	for (int i = 0; i < R; i++) {
		fill(f_dist[i], f_dist[i] + C, -1);
		fill(j_dist[i], j_dist[i] + C, -1);
	}

	queue<pair<int, int>> Q1;
	queue<pair<int, int>> Q2;

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (board[i][j] == 'F') {
				Q1.push({ i,j });
				f_dist[i][j] = 0;
			}
			if (board[i][j] == 'J') {
				Q2.push({ i,j });
				j_dist[i][j] = 0;
			}
		}
	}	

	// 불 BFS
	while (!Q1.empty()) {
		auto cur = Q1.front();
		Q1.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx < 0 || ny < 0 || nx >= R || ny >= C) continue;
			// 이미 방문했거나 벽 일때
			if (f_dist[nx][ny] >= 0 || board[nx][ny] == '#') continue;
			f_dist[nx][ny] = f_dist[cur.X][cur.Y] + 1;
			Q1.push({ nx,ny });
		}
	}

	// 지훈이 BFS
	while (!Q2.empty()) {
		auto cur = Q2.front();
		Q2.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			// 범위 검사 (이 문제는 범위를 벗어났다는 것은 탈출을 의미하므로 출력)
			if (nx < 0 || ny < 0 || nx >= R || ny >= C) {
				cout << j_dist[cur.X][cur.Y]+1;
				return 0;
			}
			// 이미 방문했거나 벽 일때
			if (j_dist[nx][ny] >= 0 || board[nx][ny] == '#') continue;
			// 불이 먼저 도달했을때
			if (f_dist[nx][ny] != -1 && f_dist[nx][ny] <= j_dist[cur.X][cur.Y]+1) continue;
			j_dist[nx][ny] = j_dist[cur.X][cur.Y] + 1;
			Q2.push({ nx,ny });
		}
	}
	cout << "IMPOSSIBLE";
}
