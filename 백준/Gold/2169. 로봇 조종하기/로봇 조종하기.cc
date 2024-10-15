#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

#define MAX 1001

int N, M;
int ground[MAX][MAX];
int dp[MAX][MAX];
int leftDp[MAX][MAX], rightDp[MAX][MAX];

int main() {
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> ground[i][j];
        }
    }

    memset(dp, 0, sizeof(dp));
    
    // 첫 번째 줄 dp 초기화
    dp[0][0] = ground[0][0];
    for (int j = 1; j < M; j++) {
        dp[0][j] = dp[0][j-1] + ground[0][j];
    }

    // 각 행에서 처리
    for (int i = 1; i < N; i++) {
        // 왼쪽에서 오른쪽으로 이동
        leftDp[i][0] = dp[i-1][0] + ground[i][0];
        for (int j = 1; j < M; j++) {
            leftDp[i][j] = max(leftDp[i][j-1], dp[i-1][j]) + ground[i][j];
        }
        
        // 오른쪽에서 왼쪽으로 이동
        rightDp[i][M-1] = dp[i-1][M-1] + ground[i][M-1];
        for (int j = M-2; j >= 0; j--) {
            rightDp[i][j] = max(rightDp[i][j+1], dp[i-1][j]) + ground[i][j];
        }

        // dp 갱신
        for (int j = 0; j < M; j++) {
            dp[i][j] = max(leftDp[i][j], rightDp[i][j]);
        }
    }

    cout << dp[N-1][M-1] << endl;

    return 0;
}
