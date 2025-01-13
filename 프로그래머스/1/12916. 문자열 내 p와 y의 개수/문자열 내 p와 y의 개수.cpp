#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
    // 대소문자 구분없이 p와 y의 개수가 같으면 True 아니면 False
    int cnt = 0;
    for (char a : s) {
        if(a == 'p' || a == 'P') cnt++;
        else if(a == 'y' || a == 'Y') cnt--;
    }
    
    return (cnt == 0 ? true : false);
}