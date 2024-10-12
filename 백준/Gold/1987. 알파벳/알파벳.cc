#include <iostream>
#include <algorithm>

#define MAX 21

using namespace std;

int R, C;
int ans;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
char board[MAX][MAX];
bool alphabet[26];

void dfs(int start, int cnt) {
    ans = max(ans, cnt);
    int curX = start % C;
    int curY = start / C;

    for(int i = 0; i < 4; i++) {
        int nx = curX + dx[i];
        int ny = curY + dy[i];

        if(nx >= 0 && nx < C && ny >= 0 && ny < R && !alphabet[board[ny][nx] - 'A']) {
            alphabet[board[ny][nx] - 'A'] = true;
            dfs(ny * C + nx, cnt + 1);
            alphabet[board[ny][nx] - 'A'] = false;
        }
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> R >> C;

    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            cin >> board[i][j];
        }
    }   

    alphabet[board[0][0] - 'A'] = true;
    dfs(0, 1);

    cout << ans << "\n";

    return 0;
}