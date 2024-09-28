#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    queue<int> Q;
   
    for (int i = 1; i <= n; i++) {
        Q.push(i);
    }

    while (1) {
        if (Q.size() == 1) {
            cout << Q.front();
            break;
        }
        if(Q.size() != 1) Q.pop();
        Q.push(Q.front());
        Q.pop();
    }

    return 0;
}
