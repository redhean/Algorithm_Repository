#include <iostream>

#define MAX 1001

using namespace std;

int n;
int dp[MAX];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> n;
    dp[1] = 1;
    dp[2] = 2;

    for(int i = 3; i <= n; i++) {
        dp[i] += (dp[i - 1] + dp[i - 2]);
        dp[i] %= 10007;
    }

    cout << dp[n] << "\n";

    return 0;
}