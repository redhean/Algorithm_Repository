#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>

#define LGN 17
#define MAX_N 100000
#define MAX_VALUE 987654321

using namespace std;

struct Node {
    int dest;
    int cost;
    Node(int dest, int cost) : dest(dest), cost(cost) {

    }
};

int N, K;
int parent_max[LGN + 1][MAX_N + 1];
int parent_min[LGN + 1][MAX_N + 1];
int parent[LGN + 1][MAX_N + 1];
int depth[MAX_N + 1];
bool visited[MAX_N + 1];
vector<Node> adjList[MAX_N  + 1];

void bfs(Node start, int dep) {
    queue<Node> q;
    q.push(start);
    depth[start.dest] = dep;
    visited[start.dest] = true;

    while(!q.empty()) {
        Node now = q.front();
        q.pop();

        for(Node next : adjList[now.dest]) {
            if(!visited[next.dest]) {
                visited[next.dest] = true;
                parent[0][next.dest] = now.dest;
                parent_max[0][next.dest] = next.cost;
                parent_min[0][next.dest] = next.cost;
                depth[next.dest] = depth[now.dest] + 1;
                q.push(next);
            }
        }
    }
}

void aces_find() {
    for(int i = 1; i <= LGN; i++) {
        for(int j = 1; j <= N; j++) {
            parent[i][j] = parent[i - 1][parent[i - 1][j]];
            parent_max[i][j] = max(parent_max[i - 1][j], parent_max[i - 1][parent[i - 1][j]]);
            parent_min[i][j] = min(parent_min[i - 1][j], parent_min[i - 1][parent[i - 1][j]]);
        }
    }
}

pair<int, int> lca(int x, int y) {
    pair<int, int> result;
    result.first = MAX_VALUE;
    result.second = 0;

    if(depth[x] > depth[y]) {
        int temp = x;
        x = y;
        y = temp;
    }

    for(int i = LGN; i >= 0; i--) {
        if(depth[y] - depth[x] >= (1 << i)){
            result.first = min(parent_min[i][y], result.first);
            result.second = max(parent_max[i][y], result.second);
            y = parent[i][y];
        }
    }

    if(x == y){
        return result;
    }

    for(int i = LGN; i >= 0; i--) {
        if(parent[i][y] != parent[i][x]) {
            result.first = min(parent_min[i][x], min(parent_min[i][y], result.first));
            result.second = max(parent_max[i][x], max(parent_max[i][y], result.second));
            y = parent[i][y];
            x = parent[i][x];
        }
    }

    result.first = min(parent_min[0][x], min(parent_min[0][y], result.first));
    result.second = max(parent_max[0][x], max(parent_max[0][y], result.second));
    return result;
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    for(int i = 0; i <= LGN; i++) {
        for(int j = 0; j < MAX_N; j++) {
            parent_min[i][j] = MAX_VALUE;
        }
    }

    cin >> N;
    for(int i = 0; i < N - 1; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        adjList[a].push_back(Node(b, c));
        adjList[b].push_back(Node(a, c));
    }

    bfs(Node(1, 0), 0);
    aces_find();

    cin >> K;
    for(int i = 0; i < K; i++) {
        int x, y;
        cin >> x >> y;
        pair<int, int> result = lca(x, y);
        cout << result.first << " " << result.second << '\n';
    }
    return 0;
}