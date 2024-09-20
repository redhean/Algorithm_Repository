#include <iostream>
#include <algorithm>
#define MAX_N 1000001

using namespace std;

int K, N;
int lan[MAX_N];
long long ans = 0;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> K >> N;

    for(int i = 0; i < K; i++) {
        cin >> lan[i];
    }

    sort(lan, lan + K);

    long long right = lan[K - 1];
    long long left = 1;

    while(left <= right) {
        long long mid = (right + left) / 2;
        int cnt = 0;

        for(int i = 0; i < K; i++) {
            cnt += lan[i] / mid;
        }

        if(cnt >= N) {
            left = mid + 1;
            if(mid > ans)
                ans = mid;
        }
        else {
            right = mid - 1;
        }
    }

    cout << ans << "\n";

    return 0;
}