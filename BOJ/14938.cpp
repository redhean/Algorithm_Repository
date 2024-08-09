#include <iostream>
#include <algorithm>

#define MAX_N 101
#define INF 123456789

using namespace std;

int dist[MAX_N][MAX_N];
int item[MAX_N];
int n, m, r;

void floyd() {
    for(int k = 1; k <= n; k++) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> n >> m >> r;

    for(int i = 1; i <= n; i++) {
        cin >> item[i];
    }

    // 초기화
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(i == j) {
                dist[i][j] = 0;
            }
            else {
                dist[i][j] = INF;
            }
        }
    }

    for(int i = 0; i < r; i++) {
        int a, b, l;

        cin >> a >> b >> l;

        dist[a][b] = l;
        dist[b][a] = l;
    }

    floyd();

    int ans = 0;
    for(int i = 1; i <= n; i++) {
        int temp_ans = 0;
        for(int j = 1; j <= n; j++) {
            if(dist[i][j] <= m) {
                temp_ans += item[j];
            }
        }

        if(ans < temp_ans) {
            ans = temp_ans;
        }
    }

    cout << ans << "\n";

    return 0;
}