#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;

#define X first
#define Y second

string board[102];
int dist[102][102];

int N, M;

int dx[4] = {1,0,-1,0};
int dy[4] = { 0,1,0,-1 };

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> board[i];
	}

	for (int i = 0; i < N; i++) {
		fill(dist[i], dist[i] + M, -1);
	}

	queue<pair<int, int>> Q;
	Q.push({ 0,0 });
	dist[0][0] = 0;

	while (!Q.empty()) {
		auto cur = Q.front();
		Q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
			if (dist[nx][ny] > 0 || board[nx][ny] != '1') continue;
			dist[nx][ny] = dist[cur.X][cur.Y] + 1;
			Q.push({ nx,ny });
		}
	}
	cout << dist[N-1][M-1]+1; // 0부터 시작이므로 dist[3][5] +1 해줘야함
}