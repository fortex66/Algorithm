#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
    bool answer = true;
    int count1 = 0;
    int count2 = 0;
    for(int i = 0; i < s.length(); i++){
        if(s[i] == 'p'){
            count1++;
        } else if(s[i] == 'P'){
            count1++;
        } else if(s[i] == 'y'){
            count2++;
        } else if(s[i] == 'Y'){
            count2++;
        }
    }
    if(count1 == 0 && count2 == 0){
        answer = true;
    } else if(count1 == count2){
        answer = true;
    } else {
        answer = false;
    }
    return answer;
}