#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N, M;
vector<int> graph[10001];

int dfs(int index, vector<bool>& visited) {
	visited[index] = true;
	int cnt = 1;
	for (int next : graph[index]) {
		if (!visited[next]) {
			cnt += dfs(next, visited);
		}
	}
	return cnt;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int x, y;
		cin >> x >> y;
		graph[y].push_back(x);
	}

	int maxCount = 0;
	vector<int> result;

	// 모든 노드들 다 탐색해보기
	for (int i = 1; i <= N; i++) {
		vector<bool> visited(N + 1, false);
		int count = dfs(i, visited);

		if (count > maxCount) {
			maxCount = count;
			result.clear();
			result.push_back(i);
		}
		else if (count == maxCount) {
			result.push_back(i);
		}
	}
	
	sort(result.begin(), result.end());
	for (int node : result) {
		cout << node << " ";
	}

}