#include <string>
#include <vector>

using namespace std;

int solution(vector<int> diffs, vector<int> times, long long limit) {
    int n = diffs.size();
    int left = 1;
    int right = 100000;
    int answer = right;
    
    while (left <= right) {
        int mid = (left + right) / 2;
        long long time = times[0];

        for (int i = 1; i < n; i++) {
            if (diffs[i] <= mid) {
                time += times[i];
            } else {
                time += (diffs[i] - mid) * (times[i] + times[i - 1]) + times[i];
            }
            
            if (time > limit) break;
        }

        if (limit >= time) {
            answer = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    
    return answer;
}
