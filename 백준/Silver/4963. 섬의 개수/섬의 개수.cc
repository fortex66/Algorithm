#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int w, h;
int board[52][52];
bool vis[52][52];

int dx[8] = { -1,0,1,0,-1,1,-1,1 };
int dy[8] = { 0,1,0,-1,-1,1,1,-1 };

void init() {
	for (int i = 0; i < 52; i++) {
		fill(vis[i], vis[i] + 52, false);
	}
}
void dfs(int x, int y) {
	vis[x][y] = true;
	for (int dir = 0; dir < 8; dir++) {
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		if (nx < 0 || nx >= h || ny < 0 || ny >= w || vis[nx][ny]) continue;
		if (board[nx][ny] == 1) {
			dfs(nx, ny);
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	//freopen("input.txt", "r", stdin);
	while (true) {
		cin >> w >> h;
		if (w == 0 && h == 0) return 0;
		
		// 초기화
		int ans = 0;
		init(); 

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> board[i][j];
			}
		}

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (!vis[i][j] && board[i][j] == 1) {
					ans++;
					dfs(i, j);
				}
			}
		}

		cout << ans << '\n';
	}
	
	return 0;
}