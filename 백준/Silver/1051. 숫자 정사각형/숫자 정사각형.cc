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
	while (rect--) {
		if (rect == 0) {
			cout << 1;
			return 0;
		}

		// 사각형 탐색 시작 범위 조절
		for (int i = 0; i <= N - (rect + 1); i++) {
			for (int j = 0; j <= M - (rect + 1); j++) {
				// 꼭지점 탐색
				if (board[i][j] == board[i][j + rect] && 
					board[i][j] == board[i + rect][j] &&
					board[i][j] == board[i + rect][j + rect]){

					cout << (rect+1) * (rect+1);
					return 0;
				}
			}
		}
		
	}
	
	return 0;
}