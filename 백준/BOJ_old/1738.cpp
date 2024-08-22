#include <iostream>
#include <vector>
#include <queue>

#define MAX 101
#define INF 987654321

using namespace std;

struct Node {
    int from;
    int to;
    int cost;
    Node(int from, int to, int cost) : from(from), to(to), cost(cost) {

    }
};

int n, m;
int dist[MAX];
int parent[MAX];
bool visited[MAX];
vector<Node> adjList;
vector<int> result;
vector<int> rev[MAX];

void bfs() {
    queue<int> q;
    q.push(n);
	visited[n] = true;
	while (!q.empty()) {
		int cidx = q.front();
		q.pop();
		for (int i = 0; i < rev[cidx].size(); i++) {
			int next = rev[cidx][i];
			if (!visited[next]) {
				visited[next] = true;
				q.push(next);
			}
		}
	}
}

void bfs2() {
    queue<int> q;
    q.push(n);

    while(!q.empty()) {
        int now = q.front();
        q.pop();
        visited[now] = 1;
        for(Node node : adjList){
            if(node.to == now && !visited[node.from]){
                q.push(node.from);
            }
        }
    }
}

bool bellmanford(int V) {

    for(int i = 1; i <= n; i++){
        dist[i] = INF;
        parent[i] = i;
    }
    
    dist[1] = 0;

    for(int i = 0; i < V - 1; i++) {
        for(Node node : adjList) {
            if(dist[node.from] == INF) continue;
            if(dist[node.to] > dist[node.from] + node.cost){
                dist[node.to] = dist[node.from] + node.cost;
                parent[node.to] = node.from;
            }
        }
    }

    bool cycle = false;

    for(Node node : adjList){
        if(dist[node.from] == INF) continue;
        if(dist[node.to] > dist[node.from] + node.cost && visited[node.from]){
            cycle = true;
            break;
        }
    }

    return cycle;
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> m;

    for(int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        adjList.push_back(Node(u, v, w * (-1)));
        rev[v].push_back(u);
    }

    bfs2();

    for(int i = 1; i<= n; i++)
        cout << visited[i] << " ";

    if(bellmanford(n)) {
        cout << -1 << '\n';
    }
    else {
        int temp = n;
        while(result.size() < n + 1) {
            if(temp == parent[temp]){
                result.push_back(temp);
                break;
            }

            result.push_back(temp);
            temp = parent[temp];
        }

        for(int i = result.size() - 1; i >= 0; i--) {
            cout << result[i] << " ";
        }
    }
    return 0;
}