#include <iostream>
#include <vector>
using namespace std;
#define X first
#define Y second

int n, m;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 }; // 남, 동, 북, 서
int board1[10][10];
int board2[10][10];
vector<pair<int, int> > cctv;

void upd(int x, int y, int dir) {
	dir %= 4;
	while (1) {
		x += dx[dir];
		y += dy[dir];
		// 범위 검사, 벽에 부딪히면
		if (x < 0 || x >= n || y < 0 || y >= m || board2[x][y] == 6) return;
		// 빈칸이 아니면 (cctv가 있는 경우) 
		if (board2[x][y] != 0) continue;
		board2[x][y] = 7; // 7로 감시 표시
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	int mn = 0; // 사각지대 최소 크기

	// 보드 만들기, cctv 좌표 백터에 저장하기
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board1[i][j];
			if (board1[i][j] != 0 && board1[i][j] != 6) {
				cctv.push_back({ i,j });
			}
			if (board1[i][j] == 0) mn++;
		}
	}

	// 총 방향의 가지수 : cctv 갯수만큼 4를 곱함 ex) 3개면 4*4*4 = 64
	int total_path = 1;
	for (int i = 0; i < cctv.size(); i++) {
		total_path *= 4;
	}

	// 방향의 가지수 만큼 cctv를 돌려보기
	for (int tmp = 0; tmp < total_path; tmp++) {
		// 보드 복사하기
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				board2[i][j] = board1[i][j];
			}
		}
		int brute = tmp; // tmp가 연산에 의해 변화하면 안되므로 복사
		// cctv 갯수만큼 탐색 시작
		for (int i = 0; i < cctv.size(); i++) {
			// 4진법 해체
			int dir = brute % 4;
			brute /= 4;
			// i 번째 cctv의 좌표
			int x = cctv[i].X;
			int y = cctv[i].Y;
			// cctv 종류별 방향 증감
			if (board2[x][y] == 1) {
				upd(x, y, dir);
			}
			else if (board2[x][y] == 2) {
				upd(x, y, dir);     // 0, 1, 2, 3
				upd(x, y, dir + 2); // 2, 3, 4, 5 -> upd안에 %4로 2, 3, 0, 1로 바뀜
			}
			else if (board2[x][y] == 3) {
				upd(x, y, dir);   // 0, 1, 2, 3
				upd(x, y, dir+1); // 1, 2, 3, 0
			}
			else if (board2[x][y] == 4) {
				upd(x, y, dir);   // 0, 1, 2, 3
				upd(x, y, dir+1); // 1, 2, 3, 0
				upd(x, y, dir+2); // 2, 3, 0, 1
			}
			else {
				upd(x, y, dir);
				upd(x, y, dir+1);
				upd(x, y, dir+2);
				upd(x, y, dir+3);
			}
		}
		int num = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (board2[i][j] == 0) num++;
			}
		}
		mn = min(mn, num);
	}
	cout << mn;
}