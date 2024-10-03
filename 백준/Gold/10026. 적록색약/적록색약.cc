#include <iostream>
#include <queue>
#include <string>
#include <utility>
using namespace std;
#define X first
#define Y second
string board[101];
int vis[101][101];
int N;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

void bfs(int i, int j) {
	queue<pair<int, int>> Q;
	Q.push({ i,j });
	vis[i][j] = 1;
	while (!Q.empty()) {
		auto cur = Q.front(); Q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
			if (vis[nx][ny] > 0 || board[cur.X][cur.Y] != board[nx][ny]) continue;
			vis[nx][ny]++;
			Q.push({ nx,ny });
		}
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> board[i];
	}

	int ans1=0, ans2=0;

	// 일반사람
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!vis[i][j]) {
				bfs(i, j);
				ans1++;
			}
		}
	}

	// vis 초기화
	for (int i = 0; i < N; i++) {
		fill(vis[i], vis[i] + N, 0);
	}

	// board에서 G를 R로 바꾸기
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (board[i][j] == 'G') {
				board[i][j] = 'R';
			}
		}
	}

	// 적록색약
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!vis[i][j]) {
				bfs(i, j);
				ans2++;
			}
		}
	}

	cout << ans1 << " " << ans2;
	return 0;
}