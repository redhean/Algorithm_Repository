#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <algorithm>
#include <cstring>

#define MAX 10001
#define INF 987654321

using namespace std;

struct Node {
    int dest;
    int cost;

    Node(int dest, int cost) : dest(dest), cost(cost) {

    }

    bool operator<(const Node& a) const {
        return cost > a.cost;
    }
};

int N, D;
int dist[MAX];
bool visited[MAX];
vector<Node> adjList[MAX];

void dijkstra() {
    priority_queue<Node> pq;

    for(int i = 0; i <= D; i++) {
        dist[i] = INF;
    }

    memset(visited, false, sizeof(visited));

    dist[0] = 0;
    pq.push(Node(0, 0));

    while(!pq.empty()) {
        Node now = pq.top();
        pq.pop();

        if(dist[now.dest] < now.cost) {
            continue;
        }

        for(Node next : adjList[now.dest]) {
            if(dist[next.dest] > now.cost + next.cost) {
                dist[next.dest] = now.cost + next.cost;
                pq.push(Node(next.dest, dist[next.dest]));
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> D;

    for(int i = 0; i < N; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        adjList[a].push_back(Node(b, c));
    }   

    for(int i = 0; i < D; i++) {
        adjList[i].push_back(Node(i + 1, 1));
    }

    dijkstra();

    cout << dist[D] << "\n";
    return 0;
}