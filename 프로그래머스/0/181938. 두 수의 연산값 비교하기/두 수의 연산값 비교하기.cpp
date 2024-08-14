#include <string>
#include <vector>

using namespace std;

int solution(int a, int b) {
    string str1 = to_string(a);
    string str2 = to_string(b);
    
    int result = stoi(str1 + str2);
    
    if(result >= (2*a*b)){
        return result;
    } else if(result < (2*a*b)){
        return 2*a*b;
    }
}