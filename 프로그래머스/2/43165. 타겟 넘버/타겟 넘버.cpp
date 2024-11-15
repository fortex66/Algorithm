#include <string>
#include <vector>
#include <queue>

using namespace std;

int answer;

void dfs(vector<int>& numbers, int & target, int sum, int n){
    int size = numbers.size();
    if(size == n){
        if(sum == target) answer++; 
        return;
    }
    
    dfs(numbers, target, sum + numbers[n], n+1);
    dfs(numbers, target, sum - numbers[n], n+1);
}

int solution(vector<int> numbers, int target) {
    
    dfs(numbers, target, -numbers[0], 1);
    dfs(numbers, target, numbers[0],1);
    
    return answer;
}