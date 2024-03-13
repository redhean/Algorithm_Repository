#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>

#define MAX 401
#define INF 987654321

using namespace std;

int V,E;
int dist[MAX][MAX];
int visited[MAX];
int ans = INF;

void floyd() {
    for(int k = 1; k <= V; k++) {
        for(int i = 1; i <= V; i++) {
            for(int j = 1; j <= V; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> V >> E;

    for(int i = 1; i <= V; i++){
        for(int j = 1; j <= V; j++) {
            if(i == j)
                dist[i][j] = 0;
            else
                dist[i][j] = INF;
        }
    }

    for(int i = 0; i < E; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        dist[a][b] = c;
    }

    floyd();

    for(int i = 1; i <= V; i++) {
        for(int j = 1; j <= V; j++) {
            if(i == j)
                continue;
            ans = min(ans, dist[i][j] + dist[j][i]);
        }
    }

    if(ans == INF)
        cout << - 1 << '\n';
    else
        cout << ans << '\n';
    return 0;
}