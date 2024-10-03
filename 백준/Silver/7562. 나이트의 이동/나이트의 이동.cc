#include <iostream>
#include <queue>
#include <string>
using namespace std;
#define X first
#define Y second
int board[302][302];
int dist[302][302];
int dx[8] = { -1,-2,-2,-1,1,2,2,1 };
int dy[8] = { -2,-1,1,2,2,1,-1,-2 };

int bfs(int x, int y, int n) {
	queue<pair<int, int>> Q;
	Q.push({ x ,y });
	while (!Q.empty()) {
		auto cur = Q.front(); Q.pop();
		for (int dir = 0; dir < 8; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
			if (dist[nx][ny] != -1) continue;
			if (board[nx][ny] == 1) {
				return dist[cur.X][cur.Y] + 2;
			}
			dist[nx][ny] = dist[cur.X][cur.Y] + 1;
			Q.push({ nx,ny });
		}
	}
}
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		
		int l, knight_x, knight_y, target_x, target_y;
		cin >> l;

		// dist 초기화
		for (int i = 0; i < l; i++) {
			for (int j = 0; j < l; j++) {
				dist[i][j] = -1;
			}
		}		

		cin >> knight_x >> knight_y;
		cin >> target_x >> target_y;

		// 타깃 지정
		board[target_x][target_y] = 1;

		int ans;
		if (knight_x == target_x && knight_y == target_y) {
			cout << 0 << '\n';
		}
		else {
			ans = bfs(knight_x, knight_y, l);
			cout << ans << '\n';
		}

		// 타깃 초기화
		board[target_x][target_y] = 0;

	}
	return 0;
}