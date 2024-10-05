#include <string>
#include <vector>
#include <map>
#include <iostream>

#define MAX 100001

using namespace std;

vector<pair<string, string>> arr;   // id, case
map<string, string> name;   // id, name

vector<string> solution(vector<string> record) {
    vector<string> answer;
    
    for(string r : record) {
        string id = "";
        string nickname = "";
        
        if(r[0] == 'E') {
            int idx = 6;
            while(r[idx] != ' ') {
                id += r[idx];
                idx++;
            }
            
            idx++;
            for(int i = idx; i < r.size(); i++)
                nickname += r[i];
            
            arr.push_back(make_pair(id, "Enter"));
            name[id] = nickname;
        }
        else if(r[0] == 'L') {
            int idx = 6;
            for(int i = idx; i < r.size(); i++) {
                id += r[i];
            }
            
            arr.push_back(make_pair(id, "Leave"));
        }
        else {
            int idx = 7;
            while(r[idx] != ' ') {
                id += r[idx];
                idx++;
            }
            
            idx++;
            for(int i = idx; i < r.size(); i++)
                nickname += r[i];
            
            arr.push_back(make_pair(id, "Change"));
            name[id] = nickname;
        }
    }
    
    for(pair<string, string> temp : arr) {
        if(temp.second == "Enter") {
            answer.push_back(name[temp.first] + "님이 들어왔습니다.");
        }
        else if(temp.second == "Leave") {
            answer.push_back(name[temp.first] + "님이 나갔습니다.");
        }
        else {
            continue;
        }
    }
    return answer;
}