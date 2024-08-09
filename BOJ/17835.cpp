#include <iostream>
#include <vector>
#include <queue>
#include <climits>

#define MAX_N 100001
#define MAX_VALUE LLONG_MAX

using namespace std;

struct Node {
    int dest;
    long long cost;

    Node(int dest, long long cost) : dest(dest), cost(cost) {

    };

    bool operator<(const Node& a) const {
        return cost > a.cost;   // 최소 힙 구현
    }
};

vector<Node> adjList[MAX_N];
long long cost[MAX_N];
bool visited[MAX_N];
int N, M, K;

void dijkstra(const vector<int>& k) {
    priority_queue<Node> pq;

    for(int i = 1; i <= N; i++) {
        cost[i] = MAX_VALUE;
        visited[i] = false;
    }

    for(int i = 0; i < k.size(); i++) {
        cost[k[i]] = 0;
        pq.push(Node(k[i], 0));
    }

    while(!pq.empty()) {
        Node now = pq.top();
        pq.pop();

        if (visited[now.dest])
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
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> N >> M >> K;

    for(int i = 0; i < M; i++) {
        int u, v;
        long long c;
        cin >> u >> v >> c;

        adjList[v].push_back(Node(u, c));   // 단방향 + 역방향
    }   

    vector<int> k;
    for(int i = 0; i < K; i++) {
        int temp;
        cin >> temp;
        k.push_back(temp);
    }

    dijkstra(k);

    int ans_city = -1;
    long long ans_cost = -1;
    for(int i = 1; i <= N; i++) {
        if(cost[i] > ans_cost) {
            ans_city = i;
            ans_cost = cost[i];
        }
    }

    cout << ans_city << "\n" << ans_cost << "\n";

    return 0;
}
