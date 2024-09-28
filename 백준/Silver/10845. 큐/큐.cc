#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    queue<int> Q;
    vector<int> V;

    for (int i = 0; i < n; i++){
        string str;
        cin >> str;
        if (str == "push") {
            int j;
            cin >> j;
            Q.push(j);
        }
        else if (str == "pop") {
            if (Q.empty()) V.push_back(-1);
            else {
                V.push_back(Q.front());
                Q.pop();
            }
        }
        else if (str == "size") {
            V.push_back(Q.size());
        }
        else if (str == "empty") {
            V.push_back(Q.empty());
        }
        else if (str == "front") {
            if (Q.empty()) V.push_back(-1);
            else V.push_back(Q.front());
        }
        else {
            if (Q.empty()) V.push_back(-1);
            else V.push_back(Q.back());
        }
    }

    for (int i = 0; i < V.size(); i++) {
        cout << V[i] << "\n";
    }

    return 0;
}
