#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> land) {
    int answer = 0;
    int temp[4] = {0, };

    for(int i = 0; i < 4; i++) {
        temp[i] = land[0][i];
    }

    for(int i = 1; i < land.size(); i++) {
        int new_temp[4] = {0, }; 

        for(int j = 0; j < 4; j++) {
            new_temp[j] = max(temp[(j + 1) % 4], max(temp[(j + 2) % 4], temp[(j + 3) % 4])) + land[i][j];
        }

        for(int j = 0; j < 4; j++) {
            temp[j] = new_temp[j];
        }
    }

    answer = *max_element(temp, temp + 4);
    return answer;
}
