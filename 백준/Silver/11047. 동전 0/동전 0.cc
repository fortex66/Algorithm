#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    int n, k, count=0;
    cin >> n >> k;
    
    vector<int> coin;
    
    for(int i = 0; i<n; i++){
        int x;
        cin >> x;
        coin.push_back(x);
    }
    
    for(int j = n-1; j>=0; j--){
        if(k >= coin[j]){
            count += k / coin[j];
            k = k % coin[j];
        }
    }
    cout << count;
}