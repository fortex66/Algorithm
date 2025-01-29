#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dice[10];
vector<int> horses(4);
int scores[33] = 
{ 0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20,
  22, 24, 26, 28, 30, 32, 34, 36, 38, 40, 13,
  16, 19, 25, 30, 35, 22, 24, 28, 27, 26, 0 
};
int special[33]; // 파란 화살표(지름길)
int nxt[32];     // 빨간 화살표
int ans;

// dice횟수, 현재 점수
void dfs(int idx, int c_score) {
    if (idx == 10) {
        if (c_score > ans) ans = c_score;
        return;
    }

    int dice_num = dice[idx];

    for (int i = 0; i < 4; i++) {
        int horse = horses[i];

        // 선택한 말이 도착 칸일 경우 넘기기
        if (horse == 32) continue;

        for (int j = 0; j < dice_num; j++) {
            if (horse == 32) break;
            // 말을 처음 움직이고 특수 칸일 경우 지름길로 간다.
            if (j == 0 && special[horse]) {
                horse = special[horse];
            }
            // 빨간 화살표를 따라간다.
            else horse = nxt[horse];
        }

        // 말이 도착지점에 도착하지 않았고 이미 말이 있는 경우 넘기기
        if (horse != 32 && find(horses.begin(), horses.end(), horse) != horses.end()) continue;

        int tmp = horses[i];
        horses[i] = horse;
        dfs(idx + 1, c_score + scores[horse]);
        horses[i] = tmp;
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    for (int i = 0; i < 10; i++) cin >> dice[i];

    // 파란 화살표 일반 좌표로 연결
    special[5] = 21;
    special[10] = 27;
    special[15] = 29;

    // 빨간 화살표 특수 좌표로 연결 
    for (int i = 0; i < 32; i++) nxt[i] = i + 1;
    nxt[26] = 20;
    nxt[28] = 24;
    nxt[31] = 24;
    nxt[20] = 32;

    dfs(0,0);
    cout << ans;
}