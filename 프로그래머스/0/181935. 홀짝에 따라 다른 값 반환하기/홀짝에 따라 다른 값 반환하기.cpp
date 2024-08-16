#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    // 짝수는 짝수 제곱 합
    if(n % 2 == 0){
        for(int i = 2; i <= n; i+=2){
            answer += i*i;
        }
    } else { // 홀수는 홀수 합
        for(int i = 1; i <= n; i+=2){
            answer += i;
        }
        
    }
    return answer;
}