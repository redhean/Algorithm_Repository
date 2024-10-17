#include <iostream>
#include <vector>
#include <cstring>

#define MAX 10001
#define C_MAX 21

using namespace std;

int T, N, M;
int dp[MAX][C_MAX];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> T;

    for(int t = 0; t < T; t++) {
        memset(dp, 0, sizeof(dp));
        cin >> N;
        vector<int> coin;
        for(int i = 0; i < N; i++) {
            int temp;
            cin >> temp;
            coin.push_back(temp);
        }

        cin >> M;

        for(int i = 1; i <= coin.size(); i++)
            dp[0][i] = 1;

        for(int i = 1; i <= coin.size(); i++) {
            for(int j = 1; j <= M; j++) {
                if(coin[i - 1] <= j) {
                    dp[j][i] = dp[j][i - 1] + dp[j - coin[i - 1]][i];
                }
                else {
                    dp[j][i] = dp[j][i - 1];
                }
            }
        }
    
        cout << dp[M][coin.size()] << "\n";
    }

    return 0;
}