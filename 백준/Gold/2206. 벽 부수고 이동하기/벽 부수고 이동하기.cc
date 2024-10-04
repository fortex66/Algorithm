#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

string board[1002];
// [0] : 벽을 부수지 않고 간 거리
// [1] : 벽을 부수고 간 거리
int dist[1002][1002][2];

int N, M;

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
   
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
       cin >> board[i];
    }
 
    // 거리 -1로 초기화
    for (int i = 0; i < N; i++) {
       for(int j = 0; j < M; j++){
           dist[i][j][0] = dist[i][j][1] = -1;
       }
    }

    queue<tuple<int, int, int>> Q;
    Q.push({ 0,0,0 }); // 
    dist[0][0][0] = 1; // 0, 0, 0 의 거리는 1로 시작
    
   // bfs
   while (!Q.empty()) {
      int x, y, broken;
      tie(x,y,broken) = Q.front();
      Q.pop();
      
      for (int dir = 0; dir < 4; dir++) {
          int nx = x + dx[dir];
          int ny = y + dy[dir];
          
          // 범위검사
          if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
          
          // 벽이 아니고 방문하지 않았다면
          if (board[nx][ny] == '0' && dist[nx][ny][broken] == -1){
              dist[nx][ny][broken] = dist[x][y][broken]+1;
              Q.push({nx,ny,broken});
          }
          
          // 벽이고 아직 부수지 않은 경우
          if(board[nx][ny] == '1' && broken == 0 && dist[nx][ny][1] == -1 ){
              dist[nx][ny][1] = dist[x][y][0] + 1;
              Q.push({nx,ny,1});
          }
          
      }
   }
   
   int ans = -1;
   // 벽을 부수지 않고 이동한 경우
   if (dist[N-1][M-1][0] != -1) ans = dist[N-1][M-1][0];
   // 벽을 부수고 이동한 경우
   if (dist[N-1][M-1][1] != -1){
      if(ans == -1) ans = dist[N-1][M-1][1];
      // 벽을 부수지 않고 이동한 것과 벽을 부수고 이동한 경우 비교하여 최단거리
      else ans = min(ans, dist[N-1][M-1][1]);
   }
   
   cout << ans;
   return 0;
}