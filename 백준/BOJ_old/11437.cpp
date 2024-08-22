#include <iostream>
#include <vector>
#include <queue>

#define LGN 16
#define MAX_N 50000

using namespace std;

int N, M;
int parent[LGN + 1][MAX_N + 1];
int depth[MAX_N + 1];
bool visited[MAX_N + 1];
vector<int> adjList[MAX_N + 1];

void bfs(int start, int dep) {
    queue<int> q;
    q.push(start);
    depth[start] = dep;
    visited[start] = true;

    while(!q.empty()) {
        int now = q.front();
        q.pop();

        for(int next : adjList[now]) {
            if(!visited[next]) {
                visited[next] = true;
                parent[0][next] = now;
                depth[next] = depth[now] + 1;
                q.push(next);
            }
        }
    }
}

void aces_find() {
    for(int i = 1; i <= LGN; i++) {
        for(int j = 1; j <= N; j++) {
            parent[i][j] = parent[i - 1][parent[i - 1][j]];
        }
    }
}

int lca(int x, int y) {
    if(depth[x] > depth[y]) {
        int temp = x;
        x = y;
        y = temp;
    }

    for(int i = LGN; i >= 0; i--) {
        if(depth[y] - depth[x] >= (1 << i)){
            y = parent[i][y];
        }
    }

    if(x == y)
        return x;

    for(int i = LGN; i >= 0; i--) {
        if(parent[i][y] != parent[i][x]) {
            y = parent[i][y];
            x = parent[i][x];
        }
    }

    return parent[0][x];
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> N;

    for(int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }

    bfs(1, 0);
    aces_find();

    cin >> M;
    for(int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        cout << lca(a, b) << '\n';
    }
    return 0;
}