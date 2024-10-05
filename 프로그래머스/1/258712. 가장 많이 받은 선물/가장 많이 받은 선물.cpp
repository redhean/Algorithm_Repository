#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <algorithm>

using namespace std;

int n;
vector<vector<int> > table;

int getGiftRatio(int idx){
    int give = 0;
    int take = 0;

    for(int i = 0; i < n; i++){
        give += table[idx][i];
    }

    for(int i = 0; i < n; i++){
        take += table[i][idx];
    }

    return give - take;
}

int solution(vector<string> friends, vector<string> gifts) {
    int answer = 0;
    n = friends.size();
    vector<int> result(n);
    table.resize(n, vector<int>(n, 0));
    map<string, int> idx;

    for(int i = 0; i < friends.size(); i++){
        idx[friends[i]] = i;
    }

    for(auto rel : gifts){
        vector<string> temp;
        stringstream ss(rel);
        string buffer = "";

        while(getline(ss, buffer, ' ')){
            temp.emplace_back(buffer);
        }

        table[idx[temp[0]]][idx[temp[1]]]++;
    }

    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            if(i == j)
                continue;

            // 둘 다 기록이 있는 경우
            if(table[i][j] != 0 && table[j][i] != 0){
                if(table[i][j] > table[j][i]){
                    result[i]++;
                }
                else if(table[i][j] < table[j][i]){
                    result[j]++;
                }
                // 선물 지수 비교
                else{
                    int i_ratio = getGiftRatio(i);
                    int j_ratio = getGiftRatio(j);

                    if(i_ratio > j_ratio){
                        result[i]++;
                    }
                    else if(i_ratio < j_ratio){
                        result[j]++;
                    }
                }
            }
            // 둘 다 기록이 없는 경우
            else if(table[i][j] == 0 && table[j][i] == 0){
                int i_ratio = getGiftRatio(i);
                int j_ratio = getGiftRatio(j);

                if(i_ratio > j_ratio){
                    result[i]++;
                }
                else if(i_ratio < j_ratio){
                    result[j]++;
                }
            }
            // 한 쪽만 기록이 있는 경우
            else {
                if(table[i][j] != 0)
                    result[i]++;
                else
                    result[j]++;
            }
        }
    }

    answer = *max_element(result.begin(), result.end());
    return answer;
}