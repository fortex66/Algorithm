#include <string>
#include <vector>

using namespace std;

double solution(vector<int> arr) {
    double answer = 0;
    int arr_size = arr.size();
    for(int i = 0; i < arr_size; i++){
        answer += arr[i];
    }
    return answer/arr_size;
}