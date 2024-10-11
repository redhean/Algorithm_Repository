#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

#define MAX 21

using namespace std;

int N;
int ans;
int shark_size = 2;
int shark_cnt; 
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
int sea[MAX][MAX];
bool visited[MAX][MAX];
vector<pair<int, int>> eatable;

void bfs(int start) {
    queue<pair<int, int>> q;
    q.push(make_pair(start, 0));

    while(!q.empty()) {
        pair<int, int> now = q.front();
        q.pop();

        int curX = now.first % N;
        int curY = now.first / N;

        if(sea[curY][curX] != 0 && sea[curY][curX] != 9) {
            if(sea[curY][curX] < shark_size) {
                eatable.push_back(now);
                continue;
            }
        }

        visited[curY][curX] = true;

        for(int i = 0; i < 4; i++) {
            int nx = curX + dx[i];
            int ny = curY + dy[i];

            if(nx >= 0 && nx < N && ny >= 0 && ny < N && shark_size >= sea[ny][nx] && !visited[ny][nx]) {
                q.push(make_pair(ny * N + nx, now.second + 1));
                visited[ny][nx] = true;
            }
        }
    }   
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> N;
    int x = 0;
    int y = 0;

    for(int i = 0; i < N ; i++) {
        for(int j = 0; j < N; j++) {
            cin >> sea[i][j];

            if(sea[i][j] == 9) {
                x = j;
                y = i;
            }
        }
    }

    while(true) {
        memset(visited, false, sizeof(visited));
        eatable.clear();

        bfs(y * N + x);

        if(eatable.size() == 0)
            break;

        int distance = MAX * MAX;
        int pos = -1;
        for(pair<int, int> temp : eatable) {
            if(temp.second < distance) {
                pos = temp.first;
                distance = temp.second;
            }
            else if(temp.second == distance) {
                if(pos / N > temp.first / N) {
                    pos = temp.first;
                    distance = temp.second;
                }
                else if(pos / N == temp.first / N) {
                    if(pos % N > temp.first % N) {
                        pos = temp.first;
                        distance = temp.second;
                    }
                }
            }
        }

        
        sea[y][x] = 0;
        shark_cnt++;
        if(shark_cnt == shark_size) {
            shark_size++;
            shark_cnt = 0;
        }

        y = pos / N;
        x = pos % N;
        sea[y][x] = 9;

        ans += distance;
    }

    cout << ans << "\n";

    return 0;
}