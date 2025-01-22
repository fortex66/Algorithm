#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    vector<int> ans;
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        ans.push_back(a);
    }

    sort(ans.begin(), ans.end());

    for (int i = 0; i < N; i++) {
        cout << ans[i] << '\n';
    }
    return 0;
}
