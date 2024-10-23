#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define X first
#define Y second

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int ans = 0x7f7f7f7f;

// 섬에 번호 붙히기
void indexing_island(queue<pair<int, int> >& Q, int board[][102], int island[][102], int n, int idx) {
    while (!Q.empty()) {
        auto cur = Q.front(); Q.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            // 범위 검사 및 방문 검사
            if (nx < 0 || nx >= n || ny < 0 || ny >= n || island[nx][ny] != 0) continue;
            if (board[nx][ny] == 0) continue;
            island[nx][ny] = idx;
            Q.push({ nx,ny });
        }
    }
}

void shortest_dist(int island[][102],int dist[][102], int x, int y, int n) {
    queue<pair<int, int> > Q;
    Q.push({ x,y });
    dist[x][y] = 0;
    while (!Q.empty()) {
        auto cur = Q.front(); Q.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if (nx < 0 || nx >= n || ny < 0 || ny >= n || dist[nx][ny] != -1) continue;
            if (island[nx][ny] == island[x][y]) continue;
            if (island[nx][ny] != 0 && island[nx][ny] != island[x][y]){
                ans = min(ans, dist[cur.X][cur.Y]);
                while (!Q.empty()) Q.pop();
                break;
            }
            Q.push({ nx,ny });
            dist[nx][ny] = dist[cur.X][cur.Y] + 1;
        }
    }
    for (int i = 0; i < n; i++)
        fill(dist[i], dist[i] + n, -1);
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // int T; // 테스트케이스

    // cin >> T;

    // while (T--) {

        int n;
        int idx = 1; // 섬 번호
        int board[102][102];
        int island[102][102] = { 0 }; // 섬 구분
        int dist[102][102]; // 거리 저장
        queue<pair<int, int> > Q;

        cin >> n;

        // 보드 입력
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> board[i][j];
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dist[i][j] = -1;
            }
        }

        // 섬에 번호 붙히기
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (island[i][j] == 0 && board[i][j] == 1) {
                    Q.push({ i,j });
                    island[i][j] = idx;
                    indexing_island(Q, board, island, n, idx);
                    idx++;
                }
            }
        }

        // 섬 최단거리 찾기
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (island[i][j] != 0) {
                    shortest_dist(island,dist, i,j,n);
                    
                }
            }
        }

        cout << ans;

    // }

    return 0;
}