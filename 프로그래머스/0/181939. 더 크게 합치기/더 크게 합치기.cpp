#include <string>
#include <vector>

using namespace std;

int solution(int a, int b) {
    int result1 = 0;
    int result2 = 0;
    
    string str1 = to_string(a) + to_string(b);
    string str2 = to_string(b) + to_string(a);
    
    result1 = stoi(str1);
    result2 = stoi(str2);
    
    if(result1 >= result2){
        return result1;
    } else if(result1 < result2){
        return result2;
    }
}