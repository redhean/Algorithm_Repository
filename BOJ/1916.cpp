#include <iostream>
#include <vector>
#include <queue>

#define MAX 1001
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

int N, M, S, E;
vector<Node> adjList[MAX];
int dist[MAX];

void dijkstra(int start) {
    priority_queue<Node> pq;
    pq.push(Node(start, 0));

    for(int i = 1; i <= N; i++)
        dist[i] = INF;
        
    while(!pq.empty()) {
        Node now = pq.top();
        pq.pop();

        if(dist[now.dest] < now.cost)
            continue;
        
        for(Node next : adjList[now.dest]) {
            if(dist[next.dest] > now.cost + next.cost) {
                dist[next.dest] = now.cost + next.cost;
                pq.push(Node(next.dest, dist[next.dest]));
            }
        }
    }
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> N >> M;

    for(int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        adjList[a].push_back(Node(b, c));
    }

    cin >> S >> E;

    dijkstra(S);

    cout << dist[E] << '\n';
    return 0;
}