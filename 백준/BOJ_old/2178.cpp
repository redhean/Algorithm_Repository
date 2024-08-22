#include <iostream>
#include <queue>
#include <string>

#define MAX 101

using namespace std;

char maze[MAX][MAX];
bool visited[MAX][MAX];

int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, 1, -1, 0};
int N, M;
int ans;

void bfs() {
    queue<pair<pair<int, int>, int>> q;
    q.push(make_pair(make_pair(1,1), 1));
    visited[1][1] = true;

    while(!q.empty()) {
        pair<pair<int, int>, int> temp = q.front();
        q.pop();
        int curX = temp.first.second;
        int curY = temp.first.first;
        int result = temp.second;

        if(curX == M && curY == N) {
            ans = result;
            return;
        }

        for(int i = 0; i < 4; i++) {
            int nx = curX + dx[i];
            int ny = curY + dy[i];

            if(nx >= 1 && nx <= M && ny >= 1 && ny <= N && maze[ny][nx] == '1' && !visited[ny][nx]) {
                visited[ny][nx] = true;
                q.push(make_pair(make_pair(ny, nx), result + 1));
            }
        }
    }
}

int main() {
    cin.tie(NULL);
	ios::sync_with_stdio(false);
    cin >> N >> M;

    for(int i = 1; i <= N; i++) {
        string temp;
        cin >> temp;

        for(int j = 1; j <= M; j++) {
            maze[i][j] = temp[j - 1];
        }
    }

    bfs();

    cout << ans << "\n";
   
    return 0;
}