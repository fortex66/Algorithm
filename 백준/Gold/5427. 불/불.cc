#include <iostream>
#include <queue>
#include <string>
using namespace std;
#define X first
#define Y second
string board[1002];
int f_dist[1002][1002];
int s_dist[1002][1002];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		bool flag = false;
		queue<pair<int, int>> Q1;
		queue<pair<int, int>> Q2;
		int w, h;
		cin >> w >> h;

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				f_dist[i][j] = s_dist[i][j] = -1;
			}
		}

		for (int i = 0; i < h; i++) {
			cin >> board[i];
			for (int j = 0; j < w; j++) {
				if (board[i][j] == '*') {
					Q1.push({ i,j });
					f_dist[i][j] = 0;
				}
				if (board[i][j] == '@') {
					Q2.push({ i,j });
					s_dist[i][j] = 0;
				}
			}
		}

		while (!Q1.empty()) {
			auto cur = Q1.front(); Q1.pop();
			for (int dir = 0; dir < 4; dir++) {
				int nx = cur.X + dx[dir];
				int ny = cur.Y + dy[dir];
				if (nx < 0 || ny < 0 || nx >= h || ny >= w) continue;
				if (f_dist[nx][ny] != -1 || board[nx][ny] == '#') continue;
				f_dist[nx][ny] = f_dist[cur.X][cur.Y] + 1;
				Q1.push({ nx,ny });
			}
		}

		while (!Q2.empty()) {
			auto cur = Q2.front(); Q2.pop();
			for (int dir = 0; dir < 4; dir++) {
				int nx = cur.X + dx[dir];
				int ny = cur.Y + dy[dir];
				if (nx < 0 || ny < 0 || nx >= h || ny >= w) {
					cout << s_dist[cur.X][cur.Y] + 1 << '\n';
					flag = true;
					break;
				}
				if (s_dist[nx][ny] != -1 || board[nx][ny] == '#') continue;
				if (f_dist[nx][ny] != -1 && f_dist[nx][ny] <= s_dist[cur.X][cur.Y] + 1) continue;
				s_dist[nx][ny] = s_dist[cur.X][cur.Y] + 1;
				Q2.push({ nx,ny });
			}
			if (flag) break;
		}

		if (!flag) cout << "IMPOSSIBLE\n";
	}
	return 0;
}