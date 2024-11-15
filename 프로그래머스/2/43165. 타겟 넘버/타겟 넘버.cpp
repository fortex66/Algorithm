#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> numbers, int target) {
    int answer = 0;
    
    queue<int> Q;
    int n = numbers.size();
    
    Q.push(0);
    
    // i는 계층 j는 계층마다 연산
    for(int i = 0; i < n; i++){
        int size = Q.size();
        for(int j = 0; j < size; j++){
            int cur = Q.front(); Q.pop();
            Q.push(cur - numbers[i]);
            Q.push(cur + numbers[i]);
        }
    }
    
    while(!Q.empty()){
        int cur = Q.front(); Q.pop();
        if(cur == target) answer++;
    }
    
    return answer;
}