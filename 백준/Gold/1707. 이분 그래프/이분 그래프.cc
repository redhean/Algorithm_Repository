#include <iostream>
#include <vector>

#define MAX 20001

using namespace std;

int K;
int chk[MAX];
vector<int> adjList[MAX];

bool dfs(int start, int c) {
    chk[start] = c;

    for(int next : adjList[start]) {
        if(chk[next] == -1) {
            if(!dfs(next, 1 - c))
                return false;
        }
        else {
            if(chk[start] == chk[next])
                return false;
        }
    }
    return true;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> K;

    for(int k = 0; k < K; k++) {
        int V, E;
        cin >> V >> E;
        for(int i = 0; i < MAX; i++) {
            adjList[i].clear();
            chk[i] = -1;
        }

        for(int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;

            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        bool isBipartite = true;
        for (int i = 1; i <= V; i++) {
            if (chk[i] == -1) { 
                if (!dfs(i, 0)) {
                    isBipartite = false;
                    break;
                }
            }
        }

        if (isBipartite) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}