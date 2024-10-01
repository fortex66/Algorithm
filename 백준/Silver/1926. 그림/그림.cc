#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;
// pair에 쓰일 first, second를 편하게 사용하려고
#define X first
#define Y second
int board[502][502]; 
bool visit[502][502];
// x가 행 y가 열 수학 좌표처럼 생각하면 안됨.
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 }; // 하 우 상 좌
int n, m; // 행 렬

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}

	int count = 0; // 그림의 개수
	int mx = 0; // 가장 넓은 그림의 넓이

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			// 0이거나 이미 방문했다면 패스
			if (board[i][j] == 0 || visit[i][j]) continue;
			count++;
			queue<pair<int, int>> Q;
			visit[i][j] = 1; // i,j 방문 표시
			Q.push({ i,j }); // 큐에 i,j 삽입
			int area = 0;
			while (!Q.empty()) {
				area++;
				// 큐에서 front 원소를 꺼내 상하좌우 검사
				pair<int, int> cur = Q.front();
				Q.pop();
				for (int dir = 0; dir < 4; dir++) {
					int nx = cur.X + dx[dir];
					int ny = cur.Y + dy[dir];
					// 조건 검사 (범위 밖인지 먼저 검사해야 런타임을 피할 수 있음)
					if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
					// 조건 검사 (이미 방문했거나 판에서 1이 아닌 경우 넘김) 
					if (visit[nx][ny] || board[nx][ny] != 1) continue;
					visit[nx][ny] = 1;
					Q.push({ nx,ny });
				}
			}
			mx = max(mx, area);
		}
	}
	cout << count << '\n' << mx;
}

