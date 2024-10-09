#include <iostream>
#include <queue>
#include <cstring>

#define MAX 501

using namespace std;

int M, N;
int map[MAX][MAX];
int dp[MAX][MAX];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

int dfs(int x, int y) {
    if(x == N - 1 && y == M - 1)
        return 1;

    if(dp[y][x] != -1)
        return dp[y][x];

    dp[y][x] = 0;
    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx >= 0 && nx < N && ny >= 0 && ny < M && map[ny][nx] < map[y][x]) {
            dp[y][x] += dfs(nx, ny);
        }
    }

    return dp[y][x];
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> M >> N;

    for(int i = 0; i < M; i++) {
        for(int j = 0; j < N; j++) {
            cin >> map[i][j];
        }
    }

    memset(dp, -1, sizeof(dp));
    cout << dfs(0, 0);

    
    return 0;
}