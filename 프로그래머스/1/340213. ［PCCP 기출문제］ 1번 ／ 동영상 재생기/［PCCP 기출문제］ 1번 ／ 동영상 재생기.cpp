#include <string>
#include <vector>
#include <iostream>

using namespace std;

int video_mm, video_ss, pos_mm, pos_ss, start_mm, start_ss, end_mm, end_ss;

void str_to_int(string a, string b, string c, string d) {
    video_mm = (a[0] - '0') * 10 + (a[1] - '0');
    video_ss = (a[3] - '0') * 10 + (a[4] - '0');
    pos_mm = (b[0] - '0') * 10 + (b[1] - '0');
    pos_ss = (b[3] - '0') * 10 + (b[4] - '0');
    start_mm = (c[0] - '0') * 10 + (c[1] - '0');
    start_ss = (c[3] - '0') * 10 + (c[4] - '0');
    end_mm = (d[0] - '0') * 10 + (d[1] - '0');
    end_ss = (d[3] - '0') * 10 + (d[4] - '0');
}

string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
    // 문자열을 숫자로 변환
    str_to_int(video_len, pos, op_start, op_end);

    for (int i = 0; i < commands.size(); i++) {
        // 오프닝 스킵
        if ((pos_mm > start_mm || (pos_mm == start_mm && pos_ss >= start_ss)) &&
            (pos_mm < end_mm || (pos_mm == end_mm && pos_ss <= end_ss))) {
            pos_mm = end_mm;
            pos_ss = end_ss;
        }

        // 명령어 처리
        if (commands[i] == "next") {
            pos_ss += 10;
            if (pos_ss >= 60) {
                pos_ss -= 60;
                pos_mm++;
            }
            if (pos_mm > video_mm || (pos_mm == video_mm && pos_ss > video_ss)) {
                pos_mm = video_mm;
                pos_ss = video_ss;
            }
        } else if (commands[i] == "prev") {
            pos_ss -= 10;
            if (pos_ss < 0) {
                pos_ss += 60;
                pos_mm--;
            }
            if (pos_mm < 0) {
                pos_mm = 0;
                pos_ss = 0;
            }
        }
    }
    
    if ((pos_mm > start_mm || (pos_mm == start_mm && pos_ss >= start_ss)) &&
    (pos_mm < end_mm || (pos_mm == end_mm && pos_ss <= end_ss))) {
    pos_mm = end_mm;
    pos_ss = end_ss;
}

    // 결과 문자열 생성
    string answer = "";
    answer += pos_mm / 10 + '0';
    answer += pos_mm % 10 + '0';
    answer += ':';
    answer += pos_ss / 10 + '0';
    answer += pos_ss % 10 + '0';
    return answer;
}
