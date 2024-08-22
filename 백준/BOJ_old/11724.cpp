#include <iostream>
#include <vector>
#include <queue>

#define MAX_N 1001

using namespace std;

vector<int> adjList[MAX_N];
bool visited[MAX_N];
int N, M;
int cnt;
int ans = 1;

void bfs(int start) {
    queue<int> q;
    q.push(start);

    while(!q.empty()) {
        int now = q.front();
        q.pop();

        if(visited[now])
            continue;

        visited[now] = true;
        cnt++;

        for(int next : adjList[now]) {
            q.push(next);
        }
    }

    if(cnt != N) {
        for(int i = 1; i <= N; i++) {
            if(!visited[i]) {
                ans++;
                bfs(i);
            }
        }
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> N >> M;

    for(int i = 0; i < M; i++) {
        int u, v;

        cin >> u >> v;

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    bfs(1);

    cout << ans << "\n";

    return 0;
}