#include <iostream>
using namespace std;

int n, m, r;
int board[301][301];
int temp[301][301]; // 임시 저장을 위한 배열

void rotateLayer(int layer) {
    int x1 = layer, y1 = layer;           // 시작 좌표
    int x2 = n - layer - 1;               // 끝 x 좌표
    int y2 = m - layer - 1;               // 끝 y 좌표

    // 위쪽 라인
    for (int i = y2; i > y1; i--) temp[x1][i - 1] = board[x1][i];
    // 오른쪽 라인
    for (int i = x2; i > x1; i--) temp[i - 1][y2] = board[i][y2];
    // 아래쪽 라인
    for (int i = y1; i < y2; i++) temp[x2][i + 1] = board[x2][i];
    // 왼쪽 라인
    for (int i = x1; i < x2; i++) temp[i + 1][y1] = board[i][y1];
}

int main() {
    cin >> n >> m >> r;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> board[i][j];

    int layers = min(n, m) / 2;  // 총 레이어 수 계산
    
    for (int j = 0; j < r; j++) {  // r번 회전
        for (int i = 0; i < layers; i++) {
            rotateLayer(i);
        }
        // temp 배열을 원래 배열에 복사
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                board[i][j] = temp[i][j];
            }
        }
    }

    // 결과 출력
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << board[i][j] << " ";
        }
        cout << '\n';
    }

    return 0;
}
