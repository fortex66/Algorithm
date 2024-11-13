#include<vector>
#include<queue>

#define X first
#define Y second

using namespace std;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int dist[102][102];

int solution(vector<vector<int> > maps)
{
    int n = maps.size();
    int m = maps[0].size();
    
    for(int i = 0; i < 102; i++){
        for(int j = 0; j < 102; j++){
            dist[i][j] = -1;
        }
    }
    
    queue<pair<int,int> > Q;
    Q.push({0,0});
    dist[0][0] = 1;
    //bfs
    while(!Q.empty()){
        auto cur = Q.front(); Q.pop();
        
        for(int dir = 0; dir < 4; dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            
            if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if(maps[nx][ny] == 0 || dist[nx][ny] != -1) continue;
            
            dist[nx][ny] = dist[cur.X][cur.Y] + 1;
            Q.push({nx,ny});
        }
    }
    
    if(dist[n-1][m-1] == -1){
        return -1;
    } else {
        return dist[n-1][m-1];
    }
    
}