#include <string>
#include <vector>
#include <queue>
#include <cstring>

#define MAX 1000001

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

vector<Node> adjList[MAX];
int cost[MAX];

void dijkstra(int start) {
    priority_queue<Node> pq;
    pq.push(Node(start, 0));
    cost[start] = 0;
    
    while(!pq.empty()) {
        Node now = pq.top();
        pq.pop();
        
        if(cost[now.dest] < now.cost) {
            continue;
        }
        
        for(Node next : adjList[now.dest]) {
            if(cost[next.dest] > next.cost + now.cost) {
                cost[next.dest] = next.cost + now.cost;
                pq.push(Node(next.dest, cost[next.dest]));
            }
        }
    }
}

int solution(int x, int y, int n) {
    for(int i = 1; i < MAX; i++) {
        if(i + n < MAX)
            adjList[i].push_back(Node(i + n, 1));
        
        if(i * 2 < MAX)
            adjList[i].push_back(Node(i * 2, 1));
        
        if(i * 3 < MAX)
            adjList[i].push_back(Node(i * 3, 1));
    }
    
    for(int i = 1; i <= y; i++)
        cost[i] = MAX;
    
    dijkstra(x);
    
    if(cost[y] != MAX)
        return cost[y];
    else
        return -1;
}