#include <string>
#include <vector>
#include <queue>


using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    // 트럭의 무게와 빠져나가는 시간을 큐에 쌍으로 기록
    queue<pair<int,int> > bridge;
    int current_time = 0; // 현재시간
    int current_weight = 0; // 현재 다리 위 무게
    int idx = 0; // 다음에 올라갈 트럭의 인덱스
    int num_trucks = truck_weights.size();
    
    while(idx < num_trucks || !bridge.empty()){
        current_time++;
        
        if(!bridge.empty()){
            if(bridge.front().second == current_time){
                current_weight -= bridge.front().first;
                bridge.pop();
            }
        }
        
        if(idx < num_trucks){
            if(current_weight + truck_weights[idx] <= weight){
                bridge.push({truck_weights[idx],current_time + bridge_length});
                current_weight += truck_weights[idx];
                idx++;
            }
        }
        
    }
    return current_time;
}