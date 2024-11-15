#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool comp(const string& a, const string& b){
    return a + b > b + a;
}

string solution(vector<int> numbers) {
    
    string answer = "";
    
    // int -> string으로 변환
    vector<string> S;
    for(int i = 0; i < numbers.size(); i++){
        S.push_back(to_string(numbers[i]));
    }
    
    sort(S.begin(), S.end(), comp);
    
    for(int i = 0; i < numbers.size(); i++){
        answer += S[i];
    }
    
    if(answer[0] == '0'){
        return "0";
    }
    
    return answer;
}