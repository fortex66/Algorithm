#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, ans, h_count;
vector<int> home;

char board[27][27];
bool visited[27][27];

int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };

void dfs(int x, int y) {

	visited[x][y] = true;
	for (int dir = 0; dir < 4; dir++) {
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		// 범위 및 방문 검사
		if (nx < 0 || nx >= n || ny < 0 || ny >= n || visited[nx][ny]) continue;
		// 벽 검사
		if (board[nx][ny] == '0') continue;
		else {
			h_count++;
			dfs(nx, ny);
		}
	}	
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	// freopen("input.txt", "r", stdin);
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!visited[i][j] && board[i][j] == '1') {
				h_count = 1;
				dfs(i, j);
				ans++;
				home.push_back(h_count);
			}
		}
	}
	
	cout << ans << '\n';
	sort(home.begin(), home.end());
	for (int i = 0; i < (int)home.size(); i++) {
		cout << home[i] << '\n';
	}
	return 0;
}