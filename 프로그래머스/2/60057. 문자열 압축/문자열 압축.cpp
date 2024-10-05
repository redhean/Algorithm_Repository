#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string s) {
    int answer = s.size();
    
    for(int i = 1; i <= s.size() / 2; i++) {
        string result = "";
        string before = "";
        int cnt = 0;
        
        int idx = 0;
        while(true) {
            if(idx + i > s.size()) {
                if(cnt >= 2)
                    result += to_string(cnt) + before;
                else
                    result += before;
                
                for(int j = idx; j < s.size(); j++)
                    result += s[j];
            
                break;
            }
            
            string temp = s.substr(idx, i);
            idx += i;
            
            if(before == "") {
                before = temp;
                cnt = 1;
            }
            else if(before == temp) {
                cnt++;
            }
            else if(before != temp) {
                if(cnt >= 2) {
                    result += to_string(cnt) + before;
                }
                else {
                    result += before;
                }
                
                cnt = 1;
                before = temp;
            }
        }
        
        if(result.size() < answer)
            answer = result.size();
    }
    return answer;
}