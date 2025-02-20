#include <iostream>
using namespace std;

const long long MOD = 1000000000;
long long comb[410][410];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, K;
    cin >> N >> K;

    int n = N + K - 1; // 구분자 까지 포함한 개수
    int r = K - 1;     // 구분자 개수

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0 || j == i)
                comb[i][j] = 1;
            else
                comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j]) % MOD;
        }
    }

    cout << comb[n][r] << "\n";
    return 0;
}
