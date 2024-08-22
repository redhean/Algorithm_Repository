#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>

#define MAX_N 1001

using namespace std;
vector<int> adjList[MAX_N];
int edgeCount[MAX_N];
int cost[MAX_N];
int result_cost[MAX_N];
int T;
int N, K;

void topological_sort(int target) {
    queue<int> q;

    for (int i = 1; i <= N; i++) {
        if (edgeCount[i] == 0) {
            q.push(i);
        }
    }

    while(!q.empty()) {
        int now = q.front();
        q.pop();

        if(now == target)
            break;

        for(int next : adjList[now]) {
            edgeCount[next]--;
            result_cost[next] = max(result_cost[now] + cost[next], result_cost[next]);
            if(edgeCount[next] == 0) {
                q.push(next);
            }
        }
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> T;

    for(int t = 0; t < T; t++) {
        int target;
        cin >> N >> K;

        for(int i = 1; i <= N; i++) {
            cin >> cost[i];
            result_cost[i] = cost[i];
        }

        for(int i = 0; i < K; i++) {
            int X, Y;
            cin >> X >> Y;

            adjList[X].push_back(Y);
            edgeCount[Y]++;
        }

        cin >> target;

        topological_sort(target);

        cout << result_cost[target] << "\n";

        memset(cost, 0, sizeof(cost));
        memset(result_cost, 0, sizeof(cost));
        memset(edgeCount, 0, sizeof(edgeCount));
        for (int i = 0; i <= N; i++) {
            adjList[i].clear();
        }
    }

    return 0;
}