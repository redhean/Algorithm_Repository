//MST : 프림 알고리즘

#include<cstdio>
#include<vector>
#include<queue>
#include<string.h>
using namespace std;

#define MAXV    1000

struct Node {
    int dest;
    int cost;

    Node(int dest, int cost) : dest(dest), cost(cost){
    }
    bool operator<(const Node& a) const {
        return cost > a.cost;
    }
};

vector<Node> adjList[MAXV+1];
int V; // 정점 수
int E; // 간선의 수

priority_queue<Node> pq;

// MST : 프림(Prim) 알고리즘
// 시작 정점
// 정점의 개수 V
int prim(int start, int V) {
    bool visited[MAXV + 1];
    memset(visited, 0, sizeof(visited));

    int mst_cost = 0; // 간선 가중치 합의 최소 비용을 저장
    int selected = 0; // 연결된 정점의 수

    pq.push(Node(start, 0));

    while (!pq.empty()) {
        Node now = pq.top();
        pq.pop();
        // 방문한 정점이면 Skip
        if (visited[now.dest])
            continue;

        // 방문 체크
        visited[now.dest] = true;

        mst_cost += now.cost;
        selected++;

        // MST 가 완성될 경우 바로 while 문 종료 가능
        // MST 만들때마다 PQ 를 꼭 초기화 할 것 !
        // PQ 에 남아 있는 데이터가 있으면 오답이 나올 수 있음
//            if (selected == V)  // 모든 정점이 연결됨
//                return mst_cost;

        for (Node next : adjList[now.dest]) {
            if (!visited[next.dest]) {
                pq.push(next);
            }
        }
    }

    if (selected == V)  // 모든 정점이 연결됨
        return mst_cost;
    else                    // 연결 불가능한 정점이 있음
        return -1;

}

int main() {
    scanf("%d %d", &V, &E);

    for (int i = 0; i < E; i++) {
        int _start, _end, cost;
        scanf("%d %d %d", &_start, &_end, &cost);
        adjList[_start].push_back(Node(_end, cost));
        // 양방향 간선으로 만들어준다.
        adjList[_end].push_back(Node(_start, cost));
    }

    // 1번 정점에서 MST 만들기 시작
    printf("%d", prim(1, V));
}