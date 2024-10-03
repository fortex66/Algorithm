#include <iostream>
#include <queue>
#include <string>
#include <tuple>
using namespace std;
int dx[6] = { 1,0,-1,0,0,0 };
int dy[6] = { 0,1,0,-1,0,0 };
int dz[6] = { 0,0,0,0,1,-1 };
int board[102][102][102];
int dist[102][102][102];
int M, N, H;
queue<tuple<int, int, int>> Q;
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> M >> N >> H;
	
	// board 채우기, 1이면 큐에 넣기, 0이면 -1로 초기화
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				int x;
				cin >> x;
				board[j][k][i] = x;
				if (x == 1) {
					Q.push({ j,k,i });
				}
				if (x == 0) {
					dist[j][k][i] = -1;
				}
			}
		}
	}

	// bfs
	while (!Q.empty()) {
		auto cur = Q.front(); Q.pop();
		int curX, curY, curZ;
		tie(curX, curY, curZ) = cur;
		for (int dir = 0; dir < 6; dir++) {
			int nx = curX + dx[dir];
			int ny = curY + dy[dir];
			int nz = curZ + dz[dir];
			if (nx < 0 || ny < 0 || nz < 0 || nx >= N || ny >= M || nz >= H) continue;
			if (dist[nx][ny][nz] != -1 ) continue; // board가 0이 아니면 차단
			dist[nx][ny][nz] = dist[curX][curY][curZ] + 1;
			Q.push({ nx,ny,nz });
		}
	}

	int ans = 0;

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				if (dist[j][k][i] == -1) {
					cout << -1;
					return 0;
				}
				ans = max(ans, dist[j][k][i]);
			}
		}
	}
	cout << ans;
	return 0;
}