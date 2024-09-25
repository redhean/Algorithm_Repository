#include <iostream>
#include <queue>
#include <cstring>

#define MAX 100

using namespace std;

int N;
char picture[MAX * MAX + 1];
bool visited[MAX * MAX + 1];

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

void bfs_normal(int start) {
    queue<int> q;
    q.push(start);
    char now_color = picture[start];

    while(!q.empty()) {
        int now = q.front();
        q.pop();
        visited[now] = true;

        for(int i = 0; i < 4; i++) {
            int nx = now % N + dx[i];
            int ny = now / N + dy[i];
        
            if(nx >= 0 && nx < N && ny >= 0 && ny < N && !visited[ny * N + nx] && picture[ny * N + nx] == now_color) {
                visited[ny * N + nx] = true;
                q.push(ny * N + nx);
            }
        }
    }
}

void bfs_red_green(int start) {
    queue<int> q;
    q.push(start);
    char now_color = picture[start];

    while(!q.empty()) {
        int now = q.front();
        q.pop();
        visited[now] = true;

        for(int i = 0; i < 4; i++) {
            int nx = now % N + dx[i];
            int ny = now / N + dy[i];
        
            if(nx >= 0 && nx < N && ny >= 0 && ny < N && !visited[ny * N + nx] && now_color == 'B' && picture[ny * N + nx] == 'B') {
                visited[ny * N + nx] = true;
                q.push(ny * N + nx);
            }
            else if(nx >= 0 && nx < N && ny >= 0 && ny < N && !visited[ny * N + nx] && now_color != 'B' && picture[ny * N + nx] != 'B') {
                visited[ny * N + nx] = true;
                q.push(ny * N + nx);   
            }
        }
    }
}

int main() {
    ios::sync_with_stdio();
    cin.tie(0);

    cin >> N;

    for(int i = 0; i < N; i++) {
        string temp;
        cin >> temp;

        for(int j = 0; j < N; j++) {
            picture[i * N + j] = temp[j];
        }
    }

    int ans = 0;
    for(int i = 0; i < N * N; i++) {
        if(!visited[i]) {
            ans++;
            bfs_normal(i);
        }
    }

    cout << ans << " ";

    memset(visited, false, sizeof(visited));
    ans = 0;

    for(int i = 0; i < N * N; i++) {
        if(!visited[i]) {
            ans++;
            bfs_red_green(i);
        }
    }

    cout << ans << "\n";

    return 0;
}