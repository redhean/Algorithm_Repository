#include <iostream>
#include <vector>
#include <cstring>
#include <stack>

#define MAX 1001

using namespace std;

int N, M, cnt, ans;
vector<int> adjList[MAX];
int visited[MAX];

void dfs() {
    stack<int> stack;
    int start;
    for(int i = 1; i <= N; i++){
        if(visited[i] == 0){
            start = i;
            break;
        }
    }  

    stack.push(start);

    while(!stack.empty()) {
        int now = stack.top();
        stack.pop();
        visited[now] = 1;
        cnt++;

        for(int node : adjList[now]) {
            if(!visited[node]){
                stack.push(node);
            }
        }
    }  
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> N >> M;

    for(int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;

        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }       

    memset(visited, 0, sizeof(visited));
    
    while(cnt < N) {
        ans++;
        dfs();
    }

    cout << ans << endl;

    return 0;
}