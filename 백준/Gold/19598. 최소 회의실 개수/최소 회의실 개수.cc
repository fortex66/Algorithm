#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	vector<pair<int, int> > meeting(N);
	priority_queue<int, vector<int>, greater<int>> pq;

	for (int i = 0; i < N; i++) {
		cin >> meeting[i].first >> meeting[i].second;
	}

	sort(meeting.begin(), meeting.end());

	pq.push(meeting[0].second);

	for (int i = 1; i < N; i++) {
		if (meeting[i].first >= pq.top()) {
			pq.pop();
			pq.push(meeting[i].second);
		}
		else {
			pq.push(meeting[i].second);
		}
	}

	cout << pq.size();

	return 0;
}