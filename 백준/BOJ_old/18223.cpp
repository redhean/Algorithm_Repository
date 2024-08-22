#include <iostream>
#include <queue>
#include <vector>
#include <climits>

#define MAX_N 5001
#define MAX_VALUE LLONG_MAX

using namespace std;

struct Node {
    int dest;
    long long cost;

    Node(int dest, long long cost) : dest(dest), cost(cost) {

    }

    bool operator<(const Node& a) const {
        return cost > a.cost;
    }
};

vector<Node> adjList[MAX_N];
long long cost[MAX_N];
bool visited[MAX_N];
int V, E, P;

void dijkstra(int start) {
    priority_queue<Node> pq;
    pq.push(Node(start, 0));
    cost[start] = 0;

    for(int i = 1; i <= V; i++) {
        cost[i] = MAX_VALUE;
        visited[i] = false;
    }

    while(!pq.empty()) {
        Node now = pq.top();
        pq.pop();

        if(visited[now.dest])
            continue;
        
        visited[now.dest] = true;

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

    cin >> V >> E >> P;

    for(int i = 0; i < E; i++) {
        int a, b;
        long long c;

        cin >> a >> b >> c;

        adjList[a].push_back(Node(b, c));
        adjList[b].push_back(Node(a, c));
    }

    dijkstra(1);
    long long MtoP = cost[P];
    long long MtoMasan = cost[V];

    dijkstra(P);
    long long PtoMasan = cost[V];

    if(MtoMasan >= MtoP + PtoMasan || P == 1) {
        cout << "SAVE HIM\n";
    }
    else {
        cout << "GOOD BYE\n";
    }

    return 0;
}