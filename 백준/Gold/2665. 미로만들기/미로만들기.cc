#include <iostream>
#include <vector>
#include <queue>

#define MAX 50
#define INF 987654321

using namespace std;

struct Node {
    int dest;
    int cost;

    Node(int dest, int cost) : dest(dest), cost(cost) {}

    bool operator<(const Node& a) const {
        return cost > a.cost;
    }
};

int n;
int cost[MAX * MAX];
int room[MAX][MAX];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
vector<Node> adjList[MAX * MAX];

void dijkstra() {
    priority_queue<Node> pq;
    pq.push(Node(0, 0));

    for (int i = 0; i < n * n; i++)
        cost[i] = INF;

    cost[0] = 0;

    while (!pq.empty()) {
        Node now = pq.top();
        pq.pop();

        if (cost[now.dest] < now.cost)
            continue;

        for (Node next : adjList[now.dest]) {
            if (cost[next.dest] > now.cost + next.cost) {
                cost[next.dest] = now.cost + next.cost;
                pq.push(Node(next.dest, cost[next.dest]));
            }
        }
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> n;

    for (int i = 0; i < n; i++) {
        string temp;
        cin >> temp;
        for (int j = 0; j < n; j++) {
            room[i][j] = temp[j] - '0';            
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < 4; k++) {
                int ny = i + dy[k];
                int nx = j + dx[k];

                if (ny >= 0 && ny < n && nx >= 0 && nx < n) {
                    int current = i * n + j;
                    int next = ny * n + nx; 
                    if(room[ny][nx] == 0)
                        adjList[current].push_back(Node(next, 1));
                    else
                        adjList[current].push_back(Node(next, 0));   
                }
            }
        }
    }

    dijkstra();

    cout << cost[n * n - 1] << "\n";

    return 0;
}
