#include <iostream>
#include <queue>
#include <cstring>

#define MAX 5

using namespace std;

char matrix[MAX * MAX];
bool visited[MAX * MAX];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
int ans;

bool chk() {
    int s_cnt = 0;
    for(int i = 0; i < MAX * MAX; i++) {
        if(visited[i] && matrix[i] == 'S') {
            s_cnt++;
        }
    }
    return s_cnt >= 4;
}

bool bfs() {
    int start = -1;
    for(int i = 0; i < MAX * MAX; i++) {
        if(visited[i]) {
            start = i;
            break;
        }
    }

    queue<int> q;
    q.push(start);
    bool q_visited[MAX * MAX] = {false, };
    q_visited[start] = true;
    int cnt = 1;

    while(!q.empty()) {
        int now = q.front();
        q.pop();

        int curX = now % MAX;
        int curY = now / MAX;
        for(int i = 0; i < 4; i++) {
            int nx = curX + dx[i];
            int ny = curY + dy[i];
            int next = ny * MAX + nx;

            if(nx >= 0 && nx < MAX && ny >= 0 && ny < MAX && visited[next] && !q_visited[next]) {
                q_visited[next] = true;
                q.push(next);
                cnt++;
            }
        }
    }

    return cnt == 7;
}

void dfs(int idx, int cnt) {
    if(cnt == 7) {
        if(chk() && bfs()) {
            ans++;
        }
        return;
    }

    for(int i = idx; i < MAX * MAX; i++) {
        if(visited[i]) continue;
        visited[i] = true;
        dfs(i + 1, cnt + 1);
        visited[i] = false;
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    for (int i = 0; i < MAX; i++) {
        string temp;
        cin >> temp;

        for(int j = 0; j < MAX; j++) {
            matrix[i * MAX + j] = temp[j];
        }
    }

    dfs(0, 0);
    cout << ans << "\n";    

    return 0;
}
