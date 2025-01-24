#include<iostream>
#include<queue>

using namespace std;

#define X first
#define Y second

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int N, M;
int board[301][301];
queue<pair<int, int> > ice;

void melting() {
	int tmp[301][301] = { 0 };
	while (!ice.empty()) {
		auto cur = ice.front(); ice.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
			if (board[nx][ny] == 0) {
				if (board[cur.X][cur.Y] > 0) tmp[cur.X][cur.Y]++;
				else continue;
			}
		}
	}
	// 녹은게 영향을 미치면 안되므로 아래에서 빼준다.
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			board[i][j] = max(0, board[i][j] - tmp[i][j]);
		}
	}
}

// 빙산 카운팅
void iceberg(bool visit[][301], int x, int y) {
	visit[x][y] = true;
	for (int dir = 0; dir < 4; dir++) {
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		if (nx < 0 || nx >= N || ny < 0 || ny >= M || visit[nx][ny]) continue;
		if (board[nx][ny] > 0) {
			iceberg(visit, nx, ny);
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
		}
	}

	int year = 1;
	while (1) {

		bool visit[301][301] = { false };


		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (board[i][j] > 0) {
					ice.push({ i,j });
				}
			}
		}

		// 빙산 녹이기
		melting();

		int ice_cnt = 0;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (!visit[i][j] && board[i][j] > 0) {
					iceberg(visit, i, j);
					ice_cnt++;
				}
			}
		}

		if (ice_cnt >= 2) {
			cout << year;
			return 0;
		}
		else if (ice_cnt == 0) {
			cout << 0;
			return 0;
		}
		else year++;


	}
	return 0;
}