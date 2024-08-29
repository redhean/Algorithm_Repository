#include <iostream>
#include <vector>

#define MAX_N 9

using namespace std;

int N;
pair<int, int> eggs[MAX_N]; 
int ans;

void dfs(int pos, int broken) {
    if(pos == N) {
        if(ans < broken)
            ans = broken;
        return;
    }

    if(eggs[pos].first <= 0) {
        dfs(pos + 1, broken);
        return;
    }

    pair<int, int> cur = eggs[pos];
    for(int i = 0; i < N; i++) {

        if(i == pos)
            continue;

        if(eggs[i].first <= 0) {
            dfs(pos + 1, broken);
            continue;
        }   

        int add = 0;
        eggs[pos].first -= eggs[i].second;
        if(eggs[pos].first <= 0) {
            add++;
        }

        eggs[i].first -= cur.second;
        if(eggs[i].first <= 0) {
            add++;
        }
    
        dfs(pos + 1, broken + add);

        eggs[pos].first += eggs[i].second;
        eggs[i].first += cur.second;
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> N;

    for(int i = 0; i < N; i++) {
        int durability;
        int weight;

        cin >> durability >> weight;
        eggs[i] = make_pair(durability, weight);
    }
    
    dfs(0, 0);
    
    cout << ans;
    return 0;
}