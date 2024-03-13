#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

#define MAX 32000
using namespace std;

int N, M;
int edgeCount[MAX + 1];
int visited[MAX + 1];
vector<int> ordered;
vector<int> adj[MAX + 1];

void dfs(int u) {
	visited[u] = 1;
	for(int v : adj[u]) {
		if(visited[v] == 0) {
			dfs(v);
		}
	}
	
	ordered.push_back(u);
}

vector<int> topologicalSort(int N) {
	ordered.clear();
	memset(visited, 0, sizeof(visited));
	
	vector<int> startNode;
	
	for(int i = 1; i <= N; i++) {
		if(edgeCount[i] == 0) {
			startNode.push_back(i);
		}
	}
	
	for(int i : startNode) {
		if(visited[i] == 0)
			dfs(i);
	}
	
	reverse(ordered.begin(), ordered.end());
	
	return ordered;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin >> N >> M;
	
	for(int i = 0; i < M; i++) {
		int start, end;
		cin >> start >> end;
		adj[start].push_back(end);
		edgeCount[end]++;
	}
	
	vector<int> result = topologicalSort(N);
	
	for(int i = 0; i < result.size(); i++) {
		cout << result[i] << " ";
	}
	
	return 0;
}