#include <iostream>
#include <algorithm>

#define MAX 10001
#define C_MAX 101

using namespace std;

int dp[MAX];
int coin[C_MAX];
int n, k;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> n >> k;

    for(int i = 0; i < n; i++)
        cin >> coin[i];

    dp[0] = 1;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= k; j++) {
            if(coin[i - 1] <= j) {
                dp[j] = dp[j] + dp[j - coin[i - 1]];
            }
        }
    }

    cout << dp[k] << "\n";
    return 0;
}