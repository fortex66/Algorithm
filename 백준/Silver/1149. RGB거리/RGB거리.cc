#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    int dp[1001][3];  // dp[i][0]: R, dp[i][1]: G, dp[i][2]: B

    // 첫 번째 집 비용
    cin >> dp[0][0] >> dp[0][1] >> dp[0][2];

    // 두 번째 집부터 N번째 집까지 처리
    for (int i = 1; i < N; i++) {
        int costR, costG, costB;
        cin >> costR >> costG >> costB;
        dp[i][0] = costR + min(dp[i - 1][1], dp[i - 1][2]);  // 이전 집이 G 또는 B일 때의 최소 비용
        dp[i][1] = costG + min(dp[i - 1][0], dp[i - 1][2]);  // 이전 집이 R 또는 B일 때의 최소 비용
        dp[i][2] = costB + min(dp[i - 1][0], dp[i - 1][1]);  // 이전 집이 R 또는 G일 때의 최소 비용
    }

    // 마지막 집에서 R, G, B 중 최소 비용 출력
    int ans = min({ dp[N - 1][0], dp[N - 1][1], dp[N - 1][2] });
    cout << ans << "\n";

    return 0;
}
