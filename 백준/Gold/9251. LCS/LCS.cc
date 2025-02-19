#include<iostream>
#include<string>
using namespace std;

int dp[1001][1001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string str1; // ACAYKP
	string str2; // CAPCAK

	cin >> str1 >> str2;

	int n = str1.size();
	int m = str2.size();

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (str1[i-1] == str2[j-1]) {
				dp[i][j] = dp[i-1][j-1]+1;
			}
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}

	cout << dp[n][m];

	return 0;
}