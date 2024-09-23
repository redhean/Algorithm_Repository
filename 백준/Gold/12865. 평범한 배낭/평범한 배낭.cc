#include <iostream>

#define MAX_W 100001
#define MAX_N 101

using namespace std;

int N, K;
int dp[MAX_N][MAX_W];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> N >> K;

    for(int i = 1; i <= N; i++) {
        int w, v;
        cin >> w >> v;

        for(int j = 1; j <= K; j++) {
            if(w <= j) {
                if(v + dp[i - 1][j - w] > dp[i - 1][j]) {
                    dp[i][j] = v + dp[i - 1][j - w];
                }
                else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
            else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    cout << dp[N][K] << "\n";

    return 0;
}