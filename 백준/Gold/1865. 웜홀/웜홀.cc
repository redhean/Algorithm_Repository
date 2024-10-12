#include <iostream>
#include <vector>
#include <cstring>

#define MAX 501
#define INF 987654321

using namespace std;

struct Node {
    int start; 
    int end; 
    int cost;

    Node(int start, int end, int cost) : start(start), end(end), cost(cost) {

    }
};

int T;
int N, M, W;
int cost[MAX];
vector<Node> adjList;

bool bellman_ford(int start) {
    for(int i = 1; i <= N; i++)
        cost[i] = INF;

    cost[start] = 0;

    for(int i = 0; i < N - 1; i++) {
        for(Node node : adjList) {
            if(cost[node.end] > cost[node.start] + node.cost) {
                cost[node.end] = cost[node.start] + node.cost;
            }
        }
    }
    
    bool isNegativeCycle = false;

    for(Node node : adjList) {
        if(cost[node.end] > cost[node.start] + node.cost) {
            isNegativeCycle = true;
            break;
        }
    }

    return isNegativeCycle;
}


int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> T;
    for(int t = 0; t < T; t++) {
        cin >> N >> M >> W;

        adjList.clear();

        for(int i = 0; i < M; i++) {
            int S, E, T;
            cin >> S >> E >> T;
            adjList.push_back(Node(S, E, T));
            adjList.push_back(Node(E, S, T));
        }

        for(int i = 0; i < W; i++) {
            int S, E, T;
            cin >> S >> E >> T;
            adjList.push_back(Node(S, E, T * -1));
        }

        bool chk = false;
        if(bellman_ford(1)) {
            chk = true;
        }

        if(chk)
            cout << "YES" << "\n";
        else
            cout << "NO" << "\n";
    }

    return 0;
}