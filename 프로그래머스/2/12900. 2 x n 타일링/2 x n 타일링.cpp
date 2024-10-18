#include <string>
#include <vector>

#define MAX 60001
#define MOD 1000000007

int dp[MAX];

using namespace std;

int solution(int n) { 
    dp[1] = 1;
    dp[2] = 2;
        
    for(int i = 3; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
        dp[i] %= MOD;
    }
    
    return dp[n];
}