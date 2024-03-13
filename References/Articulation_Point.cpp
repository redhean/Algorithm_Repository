#include <iostream>
#include <vector>
#include <stack>

#define MAX 10001

using namespace std;

int V, E, number;
vector<int> adjList[MAX];
int order[MAX];
bool isCut[MAX];

// 단절점 검색
// low를 리턴  
int dfs(int now, bool isRoot) {
	order[now] = number++;
	int low = order[now];	// low의 초기값은 자기 자신 
	int child = 0;
	
	for(int next : adjList[now]) {
		/*
         만약 이미 DFS에서 탐색된 정점이라면
         현재 정점의 방문순서와 탐색된 정점의 방문 순서 중 min값(=low)을 찾는다.
        */
        // 이미 방문한 정점이면 Skip
		if(order[next] > 0) {
			low = min(low, order[next]);
			continue;
		}
		
		child++;
		int minValue = dfs(next, false); 
		
		 /*
        정점 A가 시작 정점(root)이 아닐 때
        A번 정점에서 자식 노드들이 정점 A를 거치지 않고
        정점 A보다 빠른 방문번호를 가진 정점으로 갈 수 없다면 단절점이다.
        */
		if (!isRoot && order[now] <= minValue) {
            isCut[now] = true;
        }

        low = min(low, minValue);
	} 
	/*
    정점 A가 시작 정점(root)일 때
    자식 수가 2개 이상이면 단절점이다.
    */
    if (isRoot) {
        isCut[now] = (child >= 2);
    }

    return low;
	
} 


int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin >> V >> E;
	
	for(int i = 0; i < E; i++){
		int a, b;
		
		cin >> a >> b;
		
		// child의 수 구하기 
		adjList[a].push_back(b);
		adjList[b].push_back(a);
	}
	
	number = 1;
	for(int i = 1; i <= V; i++) {
		if(order[i] == 0)	// 아직 방문을 안 했으면 루트로 설정하고 dfs를 시작  
			dfs(i, true);
	}
	
	int cnt = 0;
	for(int i = 1; i <= V; i++) {
		if(isCut[i])
			cnt++;
	}
	
	cout << cnt << '\n';
	
	for(int i = 1; i <= V; i++) {
		if(isCut[i])
			cout << i << " ";
	}
	return 0;
}