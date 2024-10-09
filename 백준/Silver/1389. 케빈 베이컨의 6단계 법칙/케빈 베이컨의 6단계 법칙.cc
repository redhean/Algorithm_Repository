#include <iostream>
#include <algorithm>

#define MAX 101
#define INF 987654321

using namespace std;

int cost[MAX][MAX];
int N, M;

void floyd() {
    for(int k = 1; k <= N; k++) {
        for(int i = 1; i <= N; i++) {
            for(int j = 1; j <= N; j++) {
                if(cost[i][j] > cost[i][k] + cost[k][j]) {
                    cost[i][j] = cost[i][k] + cost[k][j];
                }
            }
        }
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> N >> M;

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            if(i == j)
                cost[i][j] = 0;
            else
                cost[i][j] = INF;
        }
    }

    for(int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;

        cost[a][b] = 1;
        cost[b][a] = 1;
    }

    floyd();

    int kb = INF;
    int ans = INF;
    for(int i = 1; i <= N; i++) {
        int temp = 0;
        for(int j = 1; j <= N; j++) {
            if(cost[i][j] == INF) {
                temp = INF;
                break;
            }

            temp += cost[i][j];
        }

        if(temp < kb) {
            kb = temp;
            ans = i;
        }
    }

    cout << ans << endl;

    return 0;
}