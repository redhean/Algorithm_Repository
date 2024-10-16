#include <iostream>
#include <algorithm>

#define MAX 1001

using namespace std;

int T, W;
int dp[MAX][31];
int plum[MAX];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> T >> W;

    for (int i = 1; i <= T; i++) {
        cin >> plum[i];
    }

    for (int i = 1; i <= T; i++) {
        if (plum[i] == 1)
            dp[i][0] = dp[i - 1][0] + 1;
        else
            dp[i][0] = dp[i - 1][0];
    }

    for (int i = 1; i <= T; i++) {
        for (int j = 1; j <= W; j++) {
            if (plum[i] == 1) {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1]) + (j % 2 == 0);
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1]) + (j % 2 == 1);
            }
        }
    }

    int result = 0;
    for (int i = 0; i <= W; i++) {
        result = max(result, dp[T][i]);
    }

    cout << result << "\n";

    return 0;
}