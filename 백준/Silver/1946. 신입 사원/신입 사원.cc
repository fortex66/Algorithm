#include<iostream>
#include<algorithm>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;

	while (T--) {
		int N;
		int arr[100002] = { 0 };
		cin >> N;

		for (int i = 0; i < N; i++) {
			int a;
			cin >> a;
			cin >> arr[a];
		}

		int ans = 0;
		int interview_grade = 0x7f7f7f7f;
		for (int i = 1; i <= N; i++) {
			if (interview_grade > arr[i]) {
				ans++;
				interview_grade = arr[i];
			}
		}
		cout << ans << '\n';
	}

	

	return 0;
}