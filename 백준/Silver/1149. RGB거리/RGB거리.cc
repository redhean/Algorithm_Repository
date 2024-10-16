#include <iostream>
#include <algorithm>

using namespace std;

int dp[3];
int temp[3];
int N;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> N;

    for(int i = 0; i < N; i++) {
        int r, g, b;
        cin >> r >> g >> b;

        if(i == 0) {
            dp[0] = r;
            dp[1] = g;
            dp[2] = b;
            continue;
        }

        temp[0] = dp[0];
        temp[1] = dp[1];
        temp[2] = dp[2];

        dp[0] = min(temp[1] + r, temp[2] + r);
        dp[1] = min(temp[0] + g, temp[2] + g);
        dp[2] = min(temp[0] + b, temp[1] + b);
    }

    cout << min(dp[0], min(dp[1], dp[2]));
    return 0;
}