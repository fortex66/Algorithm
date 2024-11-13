#include <string>
#include <vector>

using namespace std;

bool vis[202]; // 컴퓨터 번호별 방문 저장

void dfs(int x, int n, vector<vector<int>>& computers){
    vis[x] = true;
    for(int y = 0; y < n; y++){
        if(!vis[y] && computers[x][y] == 1) {
            dfs(y,n,computers);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int ans = 0;
    
    for(int i = 0; i < n; i++){
        if(!vis[i]){
            dfs(i,n,computers);
            ans++;
        }
    }
    
    return ans;
}