#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool isPrime(int num){
    if(num < 2) return false;
    for(int i = 2; i < num; i++){
       if(num % i == 0) return false; 
    }
    return true;
}

int solution(string numbers) {
    vector<int> V;
    
    for(char c : numbers){
        V.push_back(c - '0');
    }
    
    sort(V.begin(),V.end());
    vector<int> Total;
    do{
        int num = 0;
        // 순열에서 한자리, 두자리 등등 뽑아서 배열에 저장
        // 1 2 3 이면
        for(int i = 0; i < V.size(); i++){
            num = num * 10 + V[i]; // num = 1, num = 10 + 2, num = 120 + 3
            Total.push_back(num);
        }
    } while(next_permutation(V.begin(),V.end()));
    
    // 중복제거
    sort(Total.begin(),Total.end());
    Total.erase(unique(Total.begin(),Total.end()),Total.end());
    
    // 소수 개수 제거
    int cnt = 0;
    for(int num : Total){
        if(isPrime(num)) cnt++;
    }
    return cnt;
}