#include <iostream>
#include <queue>
#include <cstring>

#define MAX 50

using namespace std;
int T;
int M, N, K;
int field[MAX * MAX + 1];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
int cnt;

void bfs(int start) {
    queue<int> q;
    q.push(start);

    while(!q.empty()) {
        int now = q.front();
        q.pop();
        cnt++;
        field[now] = 2;

        for(int i = 0; i < 4; i++) {
            int curRow = now / M + dy[i];
            int curCol = now % M + dx[i];

            if(curRow >= 0 && curRow < N && curCol >= 0 && curCol < M && 
            field[curRow * M + curCol] == 1) {
                q.push(curRow * M + curCol);
                field[curRow * M + curCol] = 2;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> T;

    for(int t = 0; t < T; t++) {
        // Initialization
        memset(field, 0, sizeof(field));
        cnt = 0;
        int ans = 0;
        cin >> M >> N >> K;

        for(int i = 0; i < K; i++) {
            int row, col;
            cin >> col >> row;
            field[row * M + col] = 1;
        }

        while(cnt < K) {
            for(int i = 0; i < MAX * MAX + 1; i++) {
                if(field[i] == 1) {
                    bfs(i);
                    ans++;
                }
            }
        }
        cout << ans << "\n";
    }

    return 0;
}