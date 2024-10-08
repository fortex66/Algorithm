#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define X first
#define Y second

int n,m;
int board[51][51];

vector<pair<int, int> > chicken;
vector<pair<int, int> > house;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
			if (board[i][j] == 1)
				house.push_back({ i,j });
			if (board[i][j] == 2)
				chicken.push_back({ i,j });
		}
	}
	
	int mn = 0x7f7f7f7f; // 도시 치킨 거리 최솟값
	vector<int> brute(chicken.size(), 1);
	fill(brute.begin(), brute.end() - m, 0);
	do {
		// 조합별로 집에서 치킨집까지 거리계산하기
		int dist = 0; // 도시 치킨 거리
		for (auto h : house) {
			int tmp = 0x7f7f7f7f; // 집에서 최단 치킨 거리
			for (int i = 0; i < chicken.size(); i++) {
				if (brute[i] == 0) continue;
				tmp = min(tmp, abs(chicken[i].X - h.X) + abs(chicken[i].Y - h.Y));
			}
			dist += tmp;
		}
		mn = min(mn, dist);
	} while (next_permutation(brute.begin(), brute.end()));
	cout << mn;
}