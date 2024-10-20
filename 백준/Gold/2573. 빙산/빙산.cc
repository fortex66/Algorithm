#include <iostream>
#include <vector>
#include <queue>
#define X first
#define Y second

using namespace std;

int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

// 빙하 녹이기
void melting(int board[][302] ,queue<pair<int,int> > & ice, int n, int m) {
	int tmp[302][302] = { 0 };
	while (!ice.empty()) {
		auto cur = ice.front(); ice.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (board[nx][ny] == 0) {
				if (board[cur.X][cur.Y] > 0) {
					tmp[cur.X][cur.Y]++;
				}
				else continue;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			board[i][j] = max(0,board[i][j] - tmp[i][j]);
		}
	}
}

// 빙산 카운트(dfs)
void dfs_iceberg(int board[][302], bool vis[][302], int n, int m, int x, int y) {
	vis[x][y] = true;
	for (int dir = 0; dir < 4; dir++) {
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		if (nx < 0 || nx >= n || ny < 0 || ny >= m || vis[nx][ny]) continue;
		if (board[nx][ny] > 0) {
			dfs_iceberg(board, vis, n, m, nx, ny);
		}
	}
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T; // 테스트 케이스
	//cin >> T;

	//while (T--) {

		int year = 1;
		int N, M;
		int board[302][302] = {0};
		
		cin >> N >> M;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cin >> board[i][j];
			}
		}

		while (1) {
			
			queue<pair<int, int> > ice; // 빙산의 좌표
			bool vis[302][302] = { false };

			for (int i = 0; i < N; i++) {
				for (int j = 0; j < M; j++) {
					if (board[i][j] > 0) {
						ice.push({ i,j });
					}
				}
			}

			melting(board, ice, N, M); // 빙산 녹이기

			//for (int i = 0; i < N; i++) {
			//	for (int j = 0; j < M; j++) {
			//		cout << board[i][j] << " ";
			//	}
			//	cout << '\n';
			//}
			int ice_count = 0;

			for (int i = 0; i < N; i++) {
				for (int j = 0; j < M; j++) {
					if (!vis[i][j] && board[i][j] > 0) {
						dfs_iceberg(board, vis, N, M,i,j); // 빙산 카운트
						ice_count++;
					}
				}
			}
			
			//cout << ice_count << '\n';

			if (ice_count >= 2) {
				cout << year;
				return 0;
			}
			else if(ice_count == 0){
				cout << 0;
				return 0;
			}
			else {
				year++;
			}
		//}

	}

	return 0;
}