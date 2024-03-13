#include <iostream>
#include <algorithm>

#define MAX 10001

using namespace std;

struct Node {
    int start;
    int end;
    int cost;
    Node(){}
    Node(int start, int end, int cost) : start(start), end(end), cost(cost){

    }

    bool operator<(const Node& a) const {
        return cost < a.cost;
    }
};


int V, E;
Node adjList[MAX];
int parent[MAX];

int find(int a) {
    if(parent[a] == a) return a;
    else return parent[a] = find(parent[a]);
}

void Union(int a, int b) {
    int aRoot = find(a);
    int bRoot = find(b);

    parent[aRoot] = bRoot;
} 

bool cycle(int a, int b){
    int aRoot = find(a);
    int bRoot = find(b);

    return aRoot == bRoot;
}

long long kruskal() {
    long long sum = 0;
    int selected = 0;

    sort(adjList, adjList + E);

    for(int i = 0; i < E; i++) {
        if(!cycle(adjList[i].start, adjList[i].end)){
            sum += adjList[i].cost;
            selected++;

            Union(adjList[i].start, adjList[i].end);
        }
    }

    if(selected == V - 1){
        return sum;
    }
    else
        return -1;
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> V >> E;

    for(int i = 1; i <= V; i++)
        parent[i] = i;

    for(int i = 0; i < E; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        adjList[i] = Node(a, b, c);
    }

    cout << kruskal() << '\n';

    return 0;
}