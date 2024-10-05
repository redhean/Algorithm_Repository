#include <string>

using namespace std;

string solution(int n) {
    string answer = "";
    int rule[] = {4, 1, 2}; 
    
    while (n > 0) {
        answer = to_string(rule[n % 3]) + answer; 
        n = (n - 1) / 3; 
    }

    return answer;
}
