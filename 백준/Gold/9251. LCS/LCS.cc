#include <iostream>
#include <string>
#include <algorithm>

#define MAX 1001

using namespace std;

string a,b;
int dp[MAX][MAX];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> a >> b;

    for(int i = 0; i < a.size(); i++) {
        for(int j = 0; j < b.size(); j++) {
            if(a[i] == b[j]) {
                dp[i + 1][j + 1] = dp[i][j] + 1;
            }
            else {
                dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
            }
        }
    }

    cout << dp[a.size()][b.size()] << endl;

    return 0;
}