#include <iostream>
#include <queue>
#include <utility>
using namespace std;

#define X first
#define Y second

int board[51][51];
int visit[51][51];

int T, M, N, K, x, y;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0,1,0,-1 };

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;

	while (T--) {
		cin >> M >> N >> K;

		queue<pair<int, int>> Q;
		// 배추 위치 입력받아서 board에 1로 만들기
		for (int i = 0; i < K; i++) {
			cin >> x >> y;
			board[y][x] = 1;
		}

		int ans = 0;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (board[i][j] == 1 && !visit[i][j]) {
					visit[i][j] = 1;
					Q.push({ i,j });
					while (!Q.empty()) {
						auto cur = Q.front(); Q.pop();
						for (int dir = 0; dir < 4; dir++) {
							int nx = cur.X + dx[dir];
							int ny = cur.Y + dy[dir];
							// 범위검사
							if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
							// 이미 방문했거나 배추가 없으면
							if (visit[nx][ny] == 1 || board[nx][ny] != 1) continue;
							visit[nx][ny] = 1;
							Q.push({ nx,ny });
						}
					}
					ans++;
				}
			}
		}
		cout << ans << '\n';
		for (int i = 0; i < N; i++) {
			fill(board[i], board[i] + M, 0);
			fill(visit[i], visit[i] + M, 0);
		}
	}
	return 0;
}