#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;

    for(int i = 0; i < arr.size(); i++){
        if(!answer.empty() && arr[i] != answer.back()){
            answer.push_back(arr[i]);
        } else if(i == 0) {
            answer.push_back(arr[0]);
        }
    }

    return answer;
}