#include<string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s)
{
    //bool answer = true;
    int s_size = s.size();
    stack<char> s_stack;
    
    if(s[0] == ')') return false;
    else if(s[s_size-1] == '(') return false;
    
    for(int i = 0; i < s_size; i++){
        if(s[i] == '(') {
            s_stack.push(s[i]);
        }
        else if(s[i] == ')' && !s_stack.empty()) {
            s_stack.pop();
        }
        else {
            return false;
        }
    }
    
    if(s_stack.empty()) return true;
    else return false;
    
}