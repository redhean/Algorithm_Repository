#include <iostream>
#include <algorithm>
#include <vector>

#define MAX 16

using namespace std;

int L, C;
char alp[MAX];

void dfs(vector<char> password, int cur) {
    if(password.size() == L) {
        int cnt = 0;
        for(int i = 0; i < L; i++) {
            if(password[i] == 'a' || password[i] == 'e' || password[i] == 'i' || password[i] == 'o' || password[i] == 'u') {
                cnt++;
            }
        }

        if(cnt == 0 || L - cnt < 2)
            return;

        for(int i = 0; i < L; i++) {
            cout << password[i];
        }
        cout << "\n";
        return;
    }
    else {
        for(int i = cur + 1; i < C; i++) {
            password.push_back(alp[i]);
            dfs(password, i);
            password.pop_back();
        }   
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> L >> C;
    
    for(int i = 0; i < C; i++) {
        cin >> alp[i];
    }

    sort(alp, alp + C);

    vector<char> password;
    dfs(password, -1);

    return 0;
}