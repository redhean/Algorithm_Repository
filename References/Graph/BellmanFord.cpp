#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

#define INF 987654321987654321
#define MAX_N 3000

using namespace std;

struct Node {
    int start;
    int end;
    int cost;
    Node(int start, int end, int cost) : start(start), end(end), cost(cost) {

    }
};

long long dist[MAX_N];
vector<Node> adjList;

// V : 정점의 수
// E : 간선의 수
// start : 시작의 정점
bool BellmanFord(int V, int E, int start) {
    // 무한대 값으로 초기화
    for(int i = 1; i <= V; i++) {
        dist[i] = INF;
    }

    dist[start] = 0;

    for(int i = 0; i < V - 1; i++) {
        for(Node node : adjList) {
            if(dist[node.start] == INF) continue;

            if(dist[node.end] > dist[node.start] + node.cost) {
                dist[node.end] = dist[node.start] + node.cost;
            } 
        }
    }

    bool isNegativeCycle = false;
    for(Node node : adjList) {
        if(dist[node.start] == INF) continue;

        if(dist[node.end] > dist[node.start] + node.cost){
            isNegativeCycle = true;
            break;
        }
    }

    return isNegativeCycle;
}

int main() {
    int N, M;

    cin >> N >> M;

    for(int i = 0; i < M; i++) {
        int S, E, C;
        cin >> S >> E >> C;
        adjList.push_back(Node(S, E, C));
    }

    if(BellmanFord(N, M, 1)) {
        cout << "Is Negative Cycle" << endl;
    }
    else{
        for(int i = 1; i <= N; i++) {
            cout << dist[i] << endl;
        }
    }

    return 0;
}