#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    
    int answer = 0;
    int arr[32] = {0};
    
    for(int i = 1; i <= n; i++){
        arr[i] = 1;
    }
    for(int i = 0; i < reserve.size(); i++){
        arr[reserve[i]] = 2;
    }
    for(int i = 0; i < lost.size(); i++){
        arr[lost[i]]--;
    }
    
    for(int i = 1; i <= n; i++){
        if(arr[i] == 2){
            if((i > 1) && (arr[i-1] == 0)){
                arr[i]--;
                arr[i-1]++;
            } else if( (i < n) && (arr[i+1] == 0)){
                arr[i]--;
                arr[i+1]++;
            }
            // } else if(arr[i-1] == 0 && arr[i+1] == 0){
            //     arr[i]--;
            //     arr[i-1]++;
            // }
        }
    }
    
    for(int i = 1; i <= n; i++){
        if(arr[i] == 1 || arr[i] == 2) answer++;
    }
    
    return answer;
}