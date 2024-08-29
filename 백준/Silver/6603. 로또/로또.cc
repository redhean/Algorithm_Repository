#include <iostream>
#include <vector>
#include <cstring>

#define MAX_N 13

using namespace std;

int k;
int s[MAX_N];

void dfs(vector<int>& temp, int start) {
    if(temp.size() == 6) {
        for(int i = 0; i < 6; i++) {
            cout << temp[i] << " ";
        }
        cout << "\n";
        return;
    }

    for(int i = start; i < k; i++) {
    
        temp.push_back(s[i]);
        dfs(temp, i + 1);
        temp.pop_back();
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    while(1) {
        cin >> k;

        if(k == 0)
            break;
        
        memset(s, 0, sizeof(s));

        for(int i = 0; i < k; i++) {
            cin >> s[i];
        }

        vector<int> temp;
        dfs(temp, 0);
        cout << "\n";
    }

    return 0;
}