#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    // 1. progresses[i] + speeds[i] 해서 100 만들기
    // 2. progresses[0] == 100 일때 뒤에 progresses들도 검사하기
    // 3. 뒤에 검사하여 값이 100이면 answer에 개수 push_back()하기

    int n = progresses.size();
    int releaseIndex = 0;
    
    while(releaseIndex < n){
        for(int i = 0; i < n; i++){
            progresses[i] = progresses[i] + speeds[i];
        }
        int count = 0;
        while(releaseIndex < n && progresses[releaseIndex] >= 100){
            count++;
            releaseIndex++;
        }
        
        if (count > 0){
            answer.push_back(count);
        }
    }
   
    
    return answer;
}