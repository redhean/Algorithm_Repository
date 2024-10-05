#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    
    for(int i = 0; i < skill_trees.size(); i++) {
        int idx = 0;
        bool chk = true;
        for(int j = 0; j < skill_trees[i].size(); j++) {
            if(skill.find(skill_trees[i][j]) != string::npos) {
                if(skill_trees[i][j] == skill[idx]) {
                    idx++;
                    continue;
                }
                else {
                    chk = false;
                    break;
                }
            }
        }
        if(chk) {
            answer++;
        }
    }
    
    return answer;
}