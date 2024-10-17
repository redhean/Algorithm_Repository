#include <iostream>

#define MAX 101
#define MOD 1000000000

using namespace std;

int N;
int dp[MAX][10];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> N;

    for(int i = 1; i < 10; i++)
        dp[1][i] = 1;

    if(N == 1) {
        cout << 9 << "\n";
        return 0;
    }

    for(int i = 2; i <= N; i++) {
        for(int j = 0; j < 10; j++) {
            if(j > 0) {
                dp[i][j] += dp[i - 1][j - 1];
            }

            if(j < 9) {
                dp[i][j] += dp[i - 1][j + 1];
            }

            dp[i][j] %= MOD;
        }
    }

    int ans = 0;
    for(int i = 0; i < 10; i++) {
        ans += dp[N][i];
        ans %= MOD;
    }

    cout << ans % MOD << "\n";

    return 0;
}