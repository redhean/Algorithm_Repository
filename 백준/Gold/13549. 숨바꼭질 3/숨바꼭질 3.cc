#include <iostream>
#include <queue>
#include <vector>

#define MAX 100001
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

int N, K;
int cost[MAX];
vector<Node> adjList[MAX];

void dijkstra() {
    priority_queue<Node> pq;

    for(int i = 0; i < MAX; i++) {
        cost[i] = INF;
    }

    pq.push(Node(N, 0));
    cost[N] = 0;

    while(!pq.empty()) {
        Node now = pq.top();
        pq.pop();

        if(cost[now.dest] < now.cost)
            continue;

        for(Node next : adjList[now.dest]) {
            if(cost[next.dest] > now.cost + next.cost) {
                cost[next.dest] = now.cost + next.cost;
                pq.push(Node(next.dest, cost[next.dest]));
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;

    for(int i = 0; i < MAX; i++) {
        if(i - 1 >= 0)
            adjList[i].push_back(Node(i - 1, 1));

        if(i + 1 < MAX)
            adjList[i].push_back(Node(i + 1, 1));

        if(i * 2 < MAX)
            adjList[i].push_back(Node(i * 2, 0));
    }

    dijkstra();

    cout << cost[K] << endl;
    return 0;
}