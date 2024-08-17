#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <climits>

#define MAX_N 101

using namespace std;

struct Node {
    int dest;
    int cost;

    Node(int dest, int cost) : dest(dest), cost(cost) {

    };

    bool operator<(const Node& a) const {
        return cost > a.cost;
    }

};

int M, N;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
char maze[MAX_N][MAX_N];
vector<Node> adjList[MAX_N * MAX_N];
int cost[MAX_N * MAX_N];

// 간선 정보 구하기 
void make_edge() {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            for(int k = 0; k < 4; k++) {
                int nx = j + dx[k];
                int ny = i + dy[k];

                if(nx >= 0 && nx < M && ny >= 0 && ny < N) {
                    adjList[i * M + j].push_back(Node(ny * M + nx, maze[ny][nx] - '0'));
                }
            }
        }
    }
}

// 비용 구하기
void dijkstra() {
    priority_queue<Node> pq;

    for(int i = 0; i < N * M; i++) {
        cost[i] = INT_MAX;
    }

    pq.push(Node(0, 0));
    cost[0] = 0;

    while(!pq.empty()) {
        Node now = pq.top();
        pq.pop();

        if(cost[now.dest] < now.cost) {
            continue;
        }

        for(Node next : adjList[now.dest]) {
            if(cost[next.dest] > next.cost + now.cost) {
                cost[next.dest] = next.cost + now.cost;
                pq.push(Node(next.dest, cost[next.dest])); 
            }
        }
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> M >> N;

    for(int i = 0; i < N; i++) {
        string temp;
        cin >> temp;

        for(int j = 0; j < M; j++) {
            maze[i][j] = temp[j];
        }
    }

    make_edge();

    dijkstra();

    cout << cost[N * M - 1] << "\n";

    return 0;
}