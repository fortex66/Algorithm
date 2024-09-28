#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    vector<int> heights(N + 1); // 탑의 높이를 저장할 벡터
    stack<int> S;
    vector<int> result(N + 1);  // 결과를 저장할 벡터

    for (int i = 1; i <= N; i++) {
        cin >> heights[i];
    }

    for (int i = 1; i <= N; i++) {
        while (!S.empty() && heights[S.top()] < heights[i]) {
            S.pop();
        }

        if (S.empty()) {
            result[i] = 0;
        }
        else {
            result[i] = S.top();
        }

        S.push(i);
    }

    for (int i = 1; i <= N; i++) {
        cout << result[i] << ' ';
    }

    return 0;
}
