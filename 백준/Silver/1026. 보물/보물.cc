#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    int n;
    int result=0;
    vector<int> arr_A;
    vector<int> arr_B;
    cin >> n;
    // A 백터에 값 넣기
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        arr_A.push_back(x);
    }
    // B 백터에 값 넣기
    for(int j = 0; j < n; j++){
        int y;
        cin >> y;
        arr_B.push_back(y);
    }
    // A 백터 정렬
    sort(arr_A.begin(), arr_A.end());
    
    // 오름차순으로 정렬된 A 백터와 B백터에서 큰 값을 곱하기
    for(int k = 0; k < n; k++){
        auto maxValue = max_element(arr_B.begin(), arr_B.end()); // 
        result = result + (*maxValue) * arr_A[k];
        arr_B.erase(maxValue);
    }
    cout << result;
}