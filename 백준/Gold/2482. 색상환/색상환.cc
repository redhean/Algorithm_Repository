#include <iostream>
#include <algorithm>

#define MAX 1001
#define MOD 1000000003

using namespace std;

int N, K;
long long dp[MAX][MAX];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> N >> K;

    for(int i = 0; i <= N; i++) {
        dp[i][0] = 1;
        dp[i][1] = i;
    }

    for(int i = 2; i <= K; i++) {
        for(int j = 2; j <= N; j++) {
            if(j == i * 2) {
                dp[j][i] = 2;
            }
            else if(j > i * 2) {
                dp[j][i] = (dp[j - 1][i] + dp[j - 2][i - 1]) % MOD;
            }
            else {
                dp[j][i] = 0;
            }
        }
    }

    cout << dp[N][K] % MOD << "\n";
    
    return 0;
}