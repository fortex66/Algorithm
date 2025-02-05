#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int k;
vector<char> inequality;		// 부등호 문자 저장
vector<bool> visit(10, false);	// 숫자 사용 여부 저장
string max_ans = "0";
string min_ans = "999999999";

// 부등호 조건 확인
bool process(char a, char b, char sign) {
	if (sign == '<') return a < b;
	if (sign == '>') return a > b;
	return false;
}

void dfs(int index, string num) {
	// 숫자를 모두 선택했다면 갱신 해주고 리턴
	if (index == k + 1) {
		if (num < min_ans) min_ans = num;
		if (num > max_ans) max_ans = num;
		return;
	}

	for (int i = 0; i < 10; i++) {
		if (!visit[i]) {
			// 첫 번째 숫자가 아니면 이전 숫자와 부등호 조건 검사
			if (index > 0 && !process(num.back(), i + '0', inequality[index - 1])) {
				continue;
			}
			visit[i] = true;
			dfs(index + 1, num + char(i + '0'));
			visit[i] = false;
		}
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);


	cin >> k;
	inequality.resize(k);
	for (int i = 0; i < k; i++) {
		cin >> inequality[i];
	}

	dfs(0, "");
	
	cout << max_ans << "\n" << min_ans;

	return 0;
}