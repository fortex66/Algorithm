#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

// 원숭이
int dx1[4] = { 0,1,0,-1 };
int dy1[4] = { 1,0,-1,0 };

// 말 
int dx2[8] = { -1, -2, -2, -1, 1, 2, 2, 1 };
int dy2[8] = { -2, -1, 1, 2, 2, 1, -1, -2 };


int board[202][202];
int vis[202][202][31];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	//int t;
	//cin >> t;
	//while (t--) {
		int k, w, h;
		int ans = 0x7f7f7f7f;
		

		cin >> k >> w >> h;

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> board[i][j]; // 보드 입력
			}
		}

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				for (int l = 0; l <= k; l++) {
					vis[i][j][l] = 0;  // 3차원 배열 초기화
				}
			}
		}


		queue<tuple<int, int,int> > Q;
		Q.push({ 0,0,0 });
		vis[0][0][0] = 1;

		while (!Q.empty()) {
			int vx, vy, vk;
			tie(vx,vy,vk) = Q.front(); Q.pop();
			// 원숭이 탐색
			for (int dir = 0; dir < 4; dir++) {
				int nx = vx + dx1[dir];
				int ny = vy + dy1[dir];
				if (nx < 0 || ny < 0 || nx >= h || ny >= w) continue;
				// 벽이거나 방문했다면 패스
				if (board[nx][ny] || vis[nx][ny][vk] ) continue;
				Q.push({ nx,ny,vk });
				vis[nx][ny][vk] = vis[vx][vy][vk] + 1;
			}

			// 말 탐색
			if (vk < k) {
				for (int dir = 0; dir < 8; dir++) {
					int nx = vx + dx2[dir];
					int ny = vy + dy2[dir];
					if (nx < 0 || ny < 0 || nx >= h || ny >= w) continue;
					// 벽이거나 방문했다면 패스
					if (board[nx][ny] ==1 || vis[nx][ny][vk+1] ) continue;
					Q.push({ nx,ny,vk+1 });
					vis[nx][ny][vk+1] = vis[vx][vy][vk] + 1;
				}
			}
		}
		for (int i = 0; i <= k; i++) {
			if (vis[h - 1][w - 1][i]) ans = min(ans, vis[h - 1][w - 1][i]);
		}
		if (ans != 0x7f7f7f7f) cout << ans-1;
		else cout << -1;
	//}

	return 0;
}