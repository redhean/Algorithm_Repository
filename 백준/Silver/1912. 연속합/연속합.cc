#include <iostream>
#include <algorithm>

#define MAX 100001

using namespace std;

int n;
int arr[MAX];
int dp[MAX];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> arr[i];

    dp[0] = arr[0];
    for(int i = 1; i < n; i++) {
        if(dp[i - 1] + arr[i] > arr[i])
            dp[i] = dp[i - 1] + arr[i];
        else
            dp[i] = arr[i];
    }
      
    cout << *max_element(dp, dp + n) << "\n";
    return 0;
}