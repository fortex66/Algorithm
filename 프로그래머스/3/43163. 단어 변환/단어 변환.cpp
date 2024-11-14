#include <string>
#include <vector>
#include <queue>

using namespace std;

bool vis[52];

int solution(string begin, string target, vector<string> words) {
    int n = words.size();
    bool flag = false;
    
    // target 검사
    for(int i = 0; i < n; i++){
        if(target == words[i]){
            flag = true;
            break;
        }
    }
    
    if(!flag){
        return 0;
    }
    
    // 탐색
    queue<pair<string,int>> Q;
    Q.push({begin, 0});
    
    while(!Q.empty()){
        string word = Q.front().first;
        int ans = Q.front().second;
        Q.pop();
        
        if(word == target){
            return ans;
        }
        
        for(int i = 0; i < n; i++){
            if(vis[i]) continue;
            
            int count = 0;
            for(int j = 0; j < word.length(); j++){
                if(word[j] != words[i][j]){
                    count++;
                }
            }
            if(count == 1){
                vis[i] = true;
                Q.push({words[i],ans+1});
            }
        }
    }
}