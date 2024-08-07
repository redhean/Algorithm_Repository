#include <iostream>
#include <queue>
#include <string>

#define MAX 1001

using namespace std;

char maze[MAX][MAX];

int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, 1, -1, 0};
int R, C, result;
int J;
int fire_time;
queue<int> F;
queue<pair<int, int>> q;

void bfs() {
    if(q.empty()) {
        result = -1;
        return;
    }

    int curX = q.front().first % C;
    int curY = q.front().first / C;
    int time = q.front().second;
    q.pop();

    if(curX == 0 || curY == 0 || curX == C - 1 || curY == R - 1) {
        result = time;
        return;
    }

    // 불 처리
    if(fire_time < time) {
        fire_time++;
        int size = F.size();
        for(int i = 0; i < size; i++) {
            int fire = F.front();
            F.pop();

            for(int j = 0; j < 4; j++) {
                int fx = (fire % C) + dx[j];
                int fy = (fire / C) + dy[j];

                if(fx >= 0 && fx < C && fy >= 0 && fy < R && maze[fy][fx] != '#' && maze[fy][fx] != 'F') {
                    maze[fy][fx] = 'F';
                    F.push(fy * C + fx);
                }
            }
        }
    }
    
    // 지훈 처리
    for(int i = 0; i < 4; i++) {
        int nx = curX + dx[i];
        int ny = curY + dy[i];

        if(nx >= 0 && nx < C && ny >= 0 && ny < R && maze[ny][nx] == '.') {
            maze[ny][nx] = 'J';
            
            q.push(make_pair(ny * C + nx, time + 1));
        }
    }  

    bfs();
}

int main() {
    cin.tie(NULL);
	ios::sync_with_stdio(false);

    cin >> R >> C;

    for(int i = 0; i < R; i++) {
        string temp;
        cin >> temp;

        for(int j = 0; j < C; j++) {
            maze[i][j] = temp[j];

            if(temp[j] == 'J') {
                J = i * C + j;
            }
            if(temp[j] == 'F') {
                F.push(i * C + j);
            }
        }
    }

    q.push(make_pair(J, 1));
    
    bfs();

    if(result == -1) {
        cout << "IMPOSSIBLE\n";
    }
    else {
        cout << result << '\n';
    }

    return 0;
}