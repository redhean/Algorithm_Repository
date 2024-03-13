#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

#define MAX_N 100001
#define MAX_VALUE 1111111111

using namespace std;

struct Node {
    int dest;
    int cost;
    Node(int dest, int cost) : dest(dest), cost(cost) {

    }
    
    bool operator<(const Node& a) const {
        return cost > a.cost;       // false일 경우 변경
    }
};

vector<Node> adjList[MAX_N];    // 인접 리스트
int cost[MAX_N];    // 정점별 비용 정리
bool visited[MAX_N];
int N, T;

void dijkstra(int start, int dest) {
    priority_queue<Node> pq;    // 간선의 비용이 가장 적은 순서로 정렬(min heap)

    // cost 배열 (무한대 값으로) 초기화
    for (int i = 1; i <= N; i++) {
        cost[i] = MAX_VALUE;
    }

    memset(visited, 0, sizeof(visited));

    cost[start] = 0;
    pq.push(Node(start, 0));

    while(!pq.empty()) {
        Node now = pq.top();
        pq.pop();

        // 수행속도 향상 : Type.1, Type.2 중 택 1
        // Type.1 start : 더 큰 가중치로 도착한 경우 패스
        if (cost[now.dest] < now.cost)
            continue;
        // Type.1 end

        // Type.2 start : 방문했던 정점이면 패스
        // *주의 "위대한 항로" 문제처럼
        // 간선의 가중치가 바뀔 수 있는 경우 오답
        if (visited[now.dest])
            continue;
        
        visited[now.dest] = true;
        // Type.2 end

        for(Node next : adjList[now.dest]) {
            // cost 가 더 작을 때만 갱신하고 PQ큐에 넣음
            if(cost[next.dest] > next.cost + now.cost) {
                cost[next.dest] = next.cost + now.cost;
                pq.push(Node(next.dest, cost[next.dest])); 
            }
        }
    }
}

// dest 값을 주지 않으면 목적지를 특정하지 않음.
// 목적지가 없으면 끝까지 수행
void dijkstra(int start) {
    dijkstra(start, -1);
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> T;

    for (int tc = 1; tc <= T; tc++) {
        int M; // 도로의 수
        cin >> N >> M;

        // 인접리스트 초기화
        for (int i = 0; i < N + 1; i++) {
            adjList[i].clear();
        }

        for (int i = 0; i < M; i++) {
            int a, b, c;
            cin >> a >> b >> c;
            adjList[a].push_back(Node(b, c));
            // 양방향 간선
            adjList[b].push_back(Node(a, c));
        }

        dijkstra(1);

        int result = cost[N] == MAX_VALUE ? -1 : cost[N];

        cout << tc << " " << result << '\n'; 
    }
}