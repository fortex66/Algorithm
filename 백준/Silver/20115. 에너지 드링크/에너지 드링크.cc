#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    int n;
    float sum = 0;
    float result = 0;
    vector<float> arr;
    
    cin >> n;
    
    for(int i =0; i<n; i++){
        int x;
        cin >> x;
        arr.push_back(x);
    }
    sort(arr.begin(),arr.end());
    
    for(int j =0; j<n-1; j++){
        sum = sum + arr[j]/2;
    }
    result = sum + arr[n-1];
    cout << result;
}