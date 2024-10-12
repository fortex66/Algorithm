// 장마를 조절하여 최대한 많은 지역을 쪼개야함
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int board[102][102];
bool vis[102][102];

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };

int ans;

void dfs(int x, int y, int h) {
	vis[x][y] = true;
	for (int dir = 0; dir < 4; dir++) {
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		// 범위 검사 및 방문 검사
		if (nx < 0 || nx >= n || ny < 0 || ny >= n || vis[nx][ny]) continue;
		// 강수량보다 높은 지대라면
		if (board[nx][ny] > h) {
			dfs(nx, ny, h);
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	// freopen("input.txt", "r", stdin);
	// int T;

	// cin >> T;

	// while (T--) {
		cin >> n;

		int mx = 0; // 높이가 가장 높은 구역

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				int x = 0;
				cin >> x;
				board[i][j] = x;
				mx = max(mx, x);
			}
		}

		// 비가 안 온 경우부터 계산
		for (int i = 0; i < mx; i++) {
			int cnt = 0;
			// 탐색 i 보다 작거나 같으면 물에 잠긴것으로 간주하고 보드 탐색
			for (int j = 0; j < n; j++) {
				for (int k = 0; k < n; k++) {
					// 방문하지 않았고 물에 잠기지 않은 지역
					if (!vis[j][k] && board[j][k] > i) {
						cnt++;
						dfs(j, k, i);
					}
				}
			}

			ans = max(ans, cnt);

			// vis 함수 초기화
			for (int j = 0; j < n; j++) {
				fill(vis[j], vis[j] + 102, false);
			}
		}

		cout << ans << '\n';
	// }

	return 0;
}