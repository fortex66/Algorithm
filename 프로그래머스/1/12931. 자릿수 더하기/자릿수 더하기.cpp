#include <iostream>

using namespace std;
int solution(int n)
{
    int answer = 0;
    for(int i = 100000000; i >= 1; i=i/10){
        answer += n/i;
        n -= n/i*i;
    }

    return answer;
}