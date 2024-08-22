#include <iostream>
#include <vector>
#include <queue>

#define MAX 987654321

using namespace std;

int N, K, M;
int ans = MAX;
int cost[101001];
vector<int> adjList[101001];

void bfs() {
    queue<int> q;
    q.push(1);
    cost[1] = 1;

    while(!q.empty()) {
        int now = q.front();
        q.pop();

        if(now == N){
            if(cost[now] < ans)
                ans = cost[now];
        }

        for(int node : adjList[now]) {
            if(!cost[node]){
                if(now > N){
                    q.push(node);
                    cost[node] = cost[now];
                } 
                else{
                    q.push(node);
                    cost[node] = cost[now] + 1;
                }
            } 
        }
    }
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> N >> K >> M;
    
    for(int i = 1; i <= M; i++) {
        // 모든 간선을 연결하면 메모리 초과 발생
        for(int j = 0; j < K; j++) {
            int a;
            cin >> a;
            adjList[a].push_back(i + N);
            adjList[i + N].push_back(a);
        }
    }

    bfs();

    if(ans == MAX)
        cout << - 1 << '\n';
    else
        cout << ans << '\n';

    return 0;
}