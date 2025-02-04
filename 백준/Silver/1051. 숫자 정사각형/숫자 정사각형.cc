#include<iostream>
#include<algorithm>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int N, M;
	string board[52];
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> board[i];
	}

	int rect = min(N, M);

	// 사각형 사이즈 조절
	while (1) {
		if (rect == 1) {
			cout << 1;
			return 0;
		}

		// 사각형 탐색 시작 범위 조절
		for (int i = 0; i <= N - rect; i++) {
			for (int j = 0; j <= M - rect; j++) {
				// 꼭지점 탐색
				if (board[i][j] == board[i][j + rect-1] && 
					board[i][j] == board[i + rect-1][j] &&
					board[i][j] == board[i + rect-1][j + rect-1]){

					cout << rect * rect;
					return 0;
				}
			}
		}
		rect--;
	}
	
	return 0;
}