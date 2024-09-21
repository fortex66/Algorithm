#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(void)
{
  string s;
  cin >> s;
  
  string num = "";
  int result = 0;
  bool minus = false;

  for(int i=0; i<=s.length(); i++){
    // 연산자라면
    if(s[i]=='-' || s[i]=='+' || i==s.length()){
      if(minus){
        result-=stoi(num);
      } else{
        result+=stoi(num);
      }
      // 마이너스를 만난후 계속 -로 만들기
      if(s[i]=='-'){
        minus = true;
      }
      num = ""; // num 초기화
    // 연산자가 아니면 문자 숫자로 만들기
    } else{
      num += s[i];
    }
  }
  cout << result;
}