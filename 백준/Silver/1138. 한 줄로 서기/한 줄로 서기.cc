#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    int n;
    cin >> n;
    vector<int> arr;
    vector<int> result(n);
    
    for(int i=0; i<n; i++){
        int x;
        cin >> x;
        arr.push_back(x);
    }
    
    for(int j=0; j<n; j++){
        int cnt=0;
        for(int k=0; k<n; k++){
            if(cnt==arr[j] && result[k]==0){
                result[k] = j+1;
                break;
            } else if(result[k]==0){
                cnt++;
            }
        }
    }
    
    for(int l=0; l<n; l++){
        cout << result[l] << " ";
    }
}