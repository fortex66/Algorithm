#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    // 큐에 (우선순위, 원래 인덱스) 저장
    queue<pair<int, int>> Q;
    // 우선순위 큐 (내림차순 정렬)
    priority_queue<int> pq;
    
    for(int i = 0; i < priorities.size(); i++){
        Q.push({priorities[i], i});
        pq.push(priorities[i]);
    }
    
    while(!Q.empty()){
        pair<int, int> current = Q.front();
        Q.pop();
        // 현재 프로세스의 우선순위가 가장 높은지 확인
        if(current.first == pq.top()){
            answer++;
            pq.pop(); // 실행된 프로세스의 우선순위를 제거
            if(current.second == location){
                return answer;
            }
        }
        else{
            // 우선순위가 더 높은 프로세스가 있으므로 다시 큐에 넣음
            Q.push(current);
        }
    }
    
    return answer;
}
