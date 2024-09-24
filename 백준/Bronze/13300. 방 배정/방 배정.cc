#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, K, S, Y, result=0;
    int arr[15] = {0,};
    cin >> N >> K;

    for (int i = 1; i <= N; i++) {
        cin >> S >> Y;
        if (S) arr[Y * 2]++;
        else arr[Y * 2 - 1]++;
    }

    for (int i = 1; i < 14; i++) {
        if (arr[i] > 0 && arr[i] <= K) result++;
        else result += (arr[i] / K) + ((arr[i] % K != 0) ? 1 : 0);
    }

    cout << result;

    return 0;
}