#include <iostream>
#include <deque>
using namespace std;

#define X first
#define Y second

int n, k, l;
int dir = 1; // 기본 방향 번호 (동)
int move_count = 0;
bool flag = false;

int board[102][102];
deque<pair<int, int> > snake;

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 }; // 북 동 남 서

void turn(char c) {
	if (c == 'D') {
		dir = (dir + 1) % 4;
	}
	else {
		dir = (dir + 3) % 4;
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k;

	// 사과 위치 설정
	for (int i = 0; i < k; i++) {
		int x, y;
		cin >> x >> y;
		board[x][y] = 1; 
	}
	
	// 방향 전환 정보 저장
	cin >> l;
	deque<pair<int, char> > directions;
	for (int i = 0; i < l; i++) {
		int x;
		char c;
		cin >> x >> c;
		directions.push_back({ x,c });
	}

	snake.push_back({ 1,1 }); // 뱀 시작위치
	board[1][1] = 2; // 뱀 위치 보드에 표시

	while (!flag) {
		move_count++;
		auto cur = snake.back();
		int nx = cur.X + dx[dir];
		int ny = cur.Y + dy[dir];

		// 이동할 위치 벽 검사 및 몸에 부딪히는 경우
		if (nx < 1 || nx > n || ny < 1 || ny > n || board[nx][ny] == 2) {
			flag = true;
			break;
		}

		// 이동한 위치에 사과가 있다면
		if (board[nx][ny] == 1) {
			board[nx][ny] = 2;
			snake.push_back({ nx,ny });
		}
		// 사과가 없다면
		else {
			board[nx][ny] = 2;
			snake.push_back({ nx,ny });
			auto tail = snake.front();
			snake.pop_front();
			board[tail.X][tail.Y] = 0;
		}

		// 방향 덱이 비어있지 않고 이동 명령과 이동한 횟수가 같으면
		if (!directions.empty() && directions.front().X == move_count) {
			turn(directions.front().Y);
			directions.pop_front();
		}
	}
	cout << move_count;
}