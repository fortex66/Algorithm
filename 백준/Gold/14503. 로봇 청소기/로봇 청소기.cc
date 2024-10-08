#include <iostream>

using namespace std;

#define X first
#define Y second

int board[52][52];
bool visited[52][52];
int n, m, x, y, d;

// 북 동 남 서
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> x >> y >> d;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> board[i][j];

    int clean_count = 0;

    while (1) {
        // 청소를 하지 않았다면 청소 처리
        if (!visited[x][y]) {
            visited[x][y] = 1;
            clean_count++;
        }

        // 현재 방향 기준으로 왼쪽부터 회전하며 빈칸 확인
        bool found = false;
        for (int i = 0; i < 4; i++) {
            d = (d + 3) % 4;
            int nx = x + dx[d];
            int ny = y + dy[d];

            if (nx >= 0 && ny >= 0 && nx < n && ny < m && board[nx][ny] == 0 && !visited[nx][ny]) {
                x = nx;
                y = ny;
                found = true;
                break;
            }
        }

        // 네 방향 모두 청소가 되어있거나 벽인 경우
        if (!found) {
            int back_x = x - dx[d];
            int back_y = y - dy[d];

            if (back_x >= 0 && back_y >= 0 && back_x < n && back_y < m && board[back_x][back_y] == 0) {
                x = back_x;
                y = back_y;
            }
            else { // 후진 시 벽인 경우
                break;
            }
        }
    }
    cout << clean_count << '\n';
    return 0;
    
}