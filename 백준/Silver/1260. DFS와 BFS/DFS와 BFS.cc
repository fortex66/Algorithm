#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int N, M, V;
int node_matrix[1001][1001];
bool visited_dfs[1001];
bool visited_bfs[1001];

// DFS
void dfs(int node) {
	visited_dfs[node] = true;
	cout << node << " ";
	for (int i = 1; i <= N; ++i) {
		if (node_matrix[node][i] && !visited_dfs[i]) {
			dfs(i);
		}
	}
}

void bfs(int start) {
	queue<int> q;
	q.push(start);
	visited_bfs[start] = true;

	while (!q.empty()) {
		int current = q.front();
		q.pop();
		cout << current << " ";

		for (int i = 1; i <= N; ++i) {
			if (node_matrix[current][i] && !visited_bfs[i]) {
				visited_bfs[i] = true;
				q.push(i);
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	// N : 정점
	// M : 간선
	// V : 시작 점
	cin >> N >> M >> V;


	for (int i = 0; i < M; ++i) {
		int start; int end;
		cin >> start >> end;
		node_matrix[start][end] = 1;
		node_matrix[end][start] = 1;
	}


	dfs(V);
	cout << '\n';

	bfs(V);

	return 0;
}