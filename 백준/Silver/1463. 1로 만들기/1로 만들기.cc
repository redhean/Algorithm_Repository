#include <iostream>
#include <algorithm>

#define MAX 1000001
using namespace std;

int N;
int dp[MAX];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> N;
    dp[2] = 1;
    dp[3] = 1;

    for(int i = 4; i <= N; i++) {
        int a = MAX;
        int b = MAX;
        int c = dp[i - 1] + 1;

        if(i % 3 == 0)
            a = dp[i / 3] + 1;
        if(i % 2 == 0)
            b = dp[i / 2] + 1;
        
        dp[i] = min(a, min(b, c));
    }


    cout << dp[N] << "\n";
    return 0;
}