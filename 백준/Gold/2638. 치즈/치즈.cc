#include <iostream>
#include <queue>
#include <vector>

#define MAX 101

using namespace std;

int N, M;
int cheese[MAX][MAX]; 
bool visited[MAX][MAX]; 
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

void bfs() {
    queue<pair<int, int>> q;
    q.push({0, 0});
    visited[0][0] = true;
    
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if (nx >= 0 && nx < M && ny >= 0 && ny < N && !visited[ny][nx] && cheese[ny][nx] == 0) {
                visited[ny][nx] = true;
                q.push({nx, ny});
            }
        }
    }
}

// 녹는 치즈 체크
bool melt_chk() {
    vector<pair<int, int>> to_melt;
    bool melted = false;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (cheese[i][j] == 1) {
                int air = 0;
                for (int k = 0; k < 4; k++) {
                    int nx = j + dx[k];
                    int ny = i + dy[k];
                    if (nx >= 0 && nx < M && ny >= 0 && ny < N && visited[ny][nx]) {
                        air++;
                    }
                }
                if (air >= 2) {
                    to_melt.push_back({i, j});
                    melted = true;
                }
            }
        }
    }

    // 녹인 치즈를 0으로 변경
    for (auto& pos : to_melt) {
        cheese[pos.first][pos.second] = 0;
    }

    return melted;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> N >> M;
    int ans = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> cheese[i][j];
        }
    }

    while (true) {
        for (int i = 0; i < N; i++) {
            fill(visited[i], visited[i] + M, false);
        }
        
        bfs();

        if (!melt_chk()) 
            break;

        ans++;
    }

    cout << ans << "\n";

    return 0;
}
