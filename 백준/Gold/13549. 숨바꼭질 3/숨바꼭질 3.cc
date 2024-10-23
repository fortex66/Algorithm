#include <iostream>
#include <deque>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	//int T;
	//cin >> T;
	//while (T--) {
		int dist[200002];
		int N, K;
		cin >> N >> K;

		fill(dist, dist + 200000, -1);

		deque<int> DQ;
		DQ.push_back(N);
		dist[N] = 0;
		while (!DQ.empty()) {
			int cur = DQ.front(); DQ.pop_front();
			if (2 * cur < 200000 && dist[2*cur] == -1) {
				DQ.push_front(2 * cur);
				dist[2 * cur] = dist[cur];
			}
			for (int nxt : {cur - 1, cur + 1}) {
				if (nxt < 0 || nxt > 100000 || dist[nxt] != -1) continue;
				DQ.push_back(nxt);
				dist[nxt] = dist[cur] + 1;
			}
		}
		cout << dist[K];
	//}

	return 0;
}