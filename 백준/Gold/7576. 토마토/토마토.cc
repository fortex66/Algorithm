#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;

#define X first
#define Y second

int board[1002][1002];
int dist[1002][1002];

int n, m;

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> m >> n;
	bool tomato = true;
	// board 입력받기
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
			if (board[i][j] == 0) tomato = false;
		}
	}
	// dist를 다 -1로 채우기
	for (int i = 0; i < n; i++) {
		fill(dist[i], dist[i] + m, -1);
	}
	
	queue<pair<int, int>> Q;
	int mx=0;

	// board가 1인 것 들 큐에넣기
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == 1) {
				Q.push({ i,j });
				dist[i][j] = 0;
			}
		}
	}

	// bfs
	while (!Q.empty()) {
		auto cur = Q.front();
		Q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			// 범위 검사
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			// 유효한 길인지 검사, 이미 방문했는지 검사
			if (board[nx][ny] == -1 || dist[nx][ny] != -1) continue;
			// 이전 dist에서 1 더하기
			int x = dist[cur.X][cur.Y] + 1;
			dist[nx][ny] = x;
			mx = max(mx, x);
			Q.push({ nx,ny });
		}
	}

	// 처음부터 토마토가 모두 익어있는 상황
	if (tomato) {
		cout << 0;
		return 0;
	}

	// 토마토가 모두 익지 못하는 상황
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (dist[i][j] == -1 && board[i][j] == 0) {
				cout << -1; 
				return 0;
			}
		}
	}

	cout << mx;
}