#include<iostream>
#include<string>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, M;
	int ans = 0x7f7f7f7f;
	string board[50];
	cin >> N >> M;

	// 보드입력
	for (int i = 0; i < N; i++) {
		cin >> board[i];
	}

	// 입력된 보드에서 8 * 8 체스판 잘라내기
	for (int i = 0; i <= N - 8; i++) {
		for (int j = 0; j <= M - 8; j++) {

			int cnt_sw = 0; // 체스판 시작이 W인 경우
			int cnt_sb = 0; // 체스판 시작이 B인 경우

			for (int k = 0; k < 8; k++) {
				for (int l = 0; l < 8; l++) {
					
					if ((k + l) % 2 == 0) {
						if (board[i + k][j + l] != 'W') cnt_sw++;
						if (board[i + k][j + l] != 'B') cnt_sb++;
					}
					else {
						if (board[i + k][j + l] != 'B') cnt_sw++;
						if (board[i + k][j + l] != 'W') cnt_sb++;
					}
				}
			}
			ans = min(ans, min(cnt_sw, cnt_sb));
		}
	}

	cout << ans << '\n';

}