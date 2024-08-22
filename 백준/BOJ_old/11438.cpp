#include <iostream>
#include <vector>
#include <cmath>
#include <queue>

#define MAX 100001
#define LGN 17  // 2^16 (65,536) < N = 100,000 < 2^17 (131,072)

using namespace std;
int N, M;
vector<int> adj[MAX];
int parent[LGN + 1][MAX];
int depth[MAX];
bool visited[MAX];

void bfs(int idx, int dep) {
    queue<int> q;
    q.push(idx);
    depth[idx] = dep;
    parent[0][idx] = 0;   // root node

    while(!q.empty()) {
        int temp = q.front();
        q.pop();
        visited[temp] = true;

        for(int a : adj[temp]) {
            if(!visited[a]) {
                depth[a] = depth[temp] + 1;
                parent[0][a] = temp;
                q.push(a);
            }
        }
    }
}

void fill_parent() {
    for(int i = 1; i <= LGN; i++) {
        for(int j = 1; j <= N; j++) {
            parent[i][j] = parent[i - 1][parent[i - 1][j]];
        }
    }
}

// x 와 y 의 공통 조상 찾기
int lca(int x, int y) {
    // 루트 기준에서 더 아래있는 정점을 y, 더 높이있는 정점을 x 로 맞춘다.
    // depth 가 더 작다는건 루트에 더 가깝다는 뜻
    // depth 가 큰 정점을 y 로 만든다.
    if (depth[x] > depth[y]) {
        int temp = x;
        x = y;
        y = temp;
    }

    // "y 의 depth" 가 "x 의 depth" 와 같아질 때까지 y 를 끌어올림 = 높이 맞추기
    for (int i = LGN; i >= 0; i--) {
        // 1 << i 값은 아래와 같다.
        // [i, 1 << i] = [17, 131072], [16, 65536], [15, 32768] ...[4, 16] [3, 8], [2, 4], [1, 2], [0, 1]
        // (1 << i) = 2 의 i 승 구하기
        if (depth[y] - depth[x] >= (1 << i)) {
            y = parent[i][y];
        }
    }

    // 동일한 높이까지 끌어올렸을 때, x 와 y 가 같다면 둘의 조상이 같다는 뜻이니
    // 그것이 최저 공통 조상이다.
    if (x == y)
        return x;

    // x 와 y 가 같지 않다면, 루트에서부터 처음으로 조상이 같지 않은 지점을 만날 때까지 탐색
    // 처음으로 달라진 위치에서 그들의 부모 중 공통 조상을 다시 찾음
    for (int i = LGN; i >= 0; i--) {
        if (parent[i][x] != parent[i][y]) {
            x = parent[i][x];
            y = parent[i][y];
        }
    }

    return parent[0][x];
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> N;
    for(int i = 0; i < N - 1; i++) {
        int start, end;
        cin >> start >> end;

        adj[start].push_back(end);
        adj[end].push_back(start);
    }

    bfs(1, 0);
    fill_parent();

    
    cin >> M;
    for(int i = 0; i < M; i++) {
        int first, second;
        cin >> first >> second;

        cout << lca(first, second) << '\n';
    }
    return 0;
}

