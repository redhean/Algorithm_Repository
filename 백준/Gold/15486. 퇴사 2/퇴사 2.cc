#include <iostream>
#include <algorithm>

#define MAX 1500001

using namespace std;

int N;
int dp[MAX];
pair<int, int> table[MAX];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> N;

    for(int i = 0; i < N; i++) {
        int T, P;
        cin >> T >> P;

        table[i] = {T, P};
    }
    
    for(int i = N - 1; i >= 0; i--) {
        if(i + table[i].first <= N) {
            dp[i] = max(dp[i + table[i].first] + table[i].second, dp[i + 1]);
        }
        else {
            dp[i] = dp[i + 1];
        }
    }

    cout << dp[0] << "\n";
    return 0;
}