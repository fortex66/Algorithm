#include<iostream>
#include<queue>
using namespace std;

int N, K, cnt;

int board[101][101];
bool visited[101];

void bfs(int node) {
	queue<int> Q;
	Q.push(node);
	visited[node] = true;

	while (!Q.empty()) {
		int cur = Q.front();
		Q.pop();
		for (int i = 1; i <= N; i++) {
			// 연결되어 있고 방문하지 않았으면 큐에 넣고 방문처리
			if (board[cur][i] && !visited[i]) {
				visited[i] = true;
				Q.push(i);
				cnt++;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> K;

	// 1번에 연결된 노드 수 구하기
	
	for (int i = 0; i < K; i++) {
		int a, b;
		cin >> a >> b;
		board[a][b] = 1;
		board[b][a] = 1;
	}

	bfs(1);
	cout << cnt;

	return 0;
}