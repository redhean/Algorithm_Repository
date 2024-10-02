#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
#include <iostream>

#define MAX 100001

using namespace std;

bool chk[MAX];

int find_next(string s, int num) {
    vector<int> temp;
    string temp_num = "";
    
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == '{')
            continue;
        else if(s[i] == '}') {
            if(temp_num != "")
                temp.push_back(stoi(temp_num));
            
            if(temp.size() == num){
                break;
            }
            else {
                temp.clear();
                temp_num = "";
            }
        }
        else if(s[i] == ',') {
            if(temp_num != "") {
                temp.push_back(stoi(temp_num));
                temp_num = "";
            }
            else {
                continue;   
            }
        }
        else {
            temp_num += s[i];
        }
    }
    
    for(int i = 0; i < temp.size(); i++) {
        if(!chk[temp[i]]) {
            chk[temp[i]] = true;
            return temp[i];
        }
    }
    return -1;
}

vector<int> solution(string s) {
    vector<int> answer;
    memset(chk, false, sizeof(chk));

    int size = count(s.begin(), s.end(), '}') - 1;
    for(int i = 0; i < size; i++) {
        int result = find_next(s, i + 1);
        if(result != -1)
            answer.push_back(result);
    }
    
    return answer;
}