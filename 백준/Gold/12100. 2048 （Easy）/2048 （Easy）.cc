#include <iostream>
#include <utility>
using namespace std;

int n;
int board1[21][21];
int board2[21][21];

void rotate() {
	int tmp[21][21];
	// 보드 복사
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			tmp[i][j] = board2[i][j];
	// 보드 회전
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			board2[i][j] = tmp[n - 1 - j][i];
	//swap(n, n);
}

void tilt(int dir) {
	while (dir--) rotate();
	for (int i = 0; i < n; i++) {
		int tilted[21] = {};
		int idx = 0;
		for (int j = 0; j < n; j++) {
			if (board2[i][j] == 0) continue;
			if (tilted[idx] == 0)
				tilted[idx] = board2[i][j];
			else if (tilted[idx] == board2[i][j])
				tilted[idx++] *= 2;
			else 
				tilted[++idx] = board2[i][j];
		}
		for (int j = 0; j < n; j++)
			board2[i][j] = tilted[j];
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < n; j++) 
			cin >> board1[i][j];

	int mx = 0;
	for (int tmp = 0; tmp < 1024; tmp++) {
		// 모드 복사
		for (int i = 0; i < n; i++) 
			for (int j = 0; j < n; j++) 
				board2[i][j] = board1[i][j];

		int brute = tmp;
		// 5번 기울이기
		for (int i = 0; i < 5; i++) {
			int dir = brute % 4;
			brute /= 4;
			tilt(dir);
		}
		// 5번 기울인 후 보드에서 최댓값 찾기
		for (int i = 0; i < n; i++) 
			for (int j = 0; j < n; j++) 
				mx = max(mx, board2[i][j]);
	}
	cout << mx;
}