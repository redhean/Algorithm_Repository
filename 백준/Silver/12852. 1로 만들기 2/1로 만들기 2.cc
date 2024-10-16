#include <iostream>

#define MAX 1000001

using namespace std;

int N;
int parent[MAX];
int dp[MAX];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> N;

    parent[1] = 1;
    dp[2] = 1;
    parent[2] = 1;
    dp[3] = 1;
    parent[3] = 1;

    for(int i = 4; i <= N; i++) {
        int result = dp[i - 1] + 1;
        parent[i] = i - 1;

        if(i % 2 == 0 && result > dp[i / 2] + 1) {
            result = dp[i / 2] + 1;
            parent[i] = i / 2;
        }

        if(i % 3 == 0 && result > dp[i / 3] + 1) {
            result = dp[i / 3] + 1;
            parent[i] = i / 3;
        }

        dp[i] = result;
    }

    cout << dp[N] << "\n";

    while(N != parent[N]) {
        cout << N << " ";
        N = parent[N];
    }
    cout << 1 << "\n";
    
    return 0;
}