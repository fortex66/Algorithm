#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    int n;
    int sum = 0;
    vector<int> arr;
    cin >> n;
    
    for(int i = 0; i<n;i++){
        int x;
        cin >> x;
        arr.push_back(x);
    }
    sort(arr.begin(), arr.end());
    
    for(int j = 0; j<n;j++){
        for(int k =0; k<j+1; k++){
            sum = sum + arr[k];
        }
    }
    cout << sum;
}