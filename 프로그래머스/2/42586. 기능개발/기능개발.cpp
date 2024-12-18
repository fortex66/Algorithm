#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int n = progresses.size();
    int idx = 0; // 반복문 시작 
    // speed의 인덱스와 progress의 인덱스 공유
    while(1){
        if(idx==n) break;
        int cnt = 0;
        for(int i = 0; i < n; i++){
            progresses[i] += speeds[i];
        }
        for(int i = idx; i < n; i++){
            if(progresses[i]<100) break;
            else cnt++; idx++;
        }
        if(cnt!=0) answer.push_back(cnt); 
    }
    return answer;
}