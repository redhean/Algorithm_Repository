#include <iostream>
#include <algorithm>

#define MAX 10001

using namespace std;

int N, K;
int sensor[MAX];
int diff[MAX - 1];
int ans;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> N >> K;

    for(int i = 0; i < N; i++) {
        cin >> sensor[i];
    }

    sort(sensor, sensor + N);

    for(int i = 1; i < N; i++) {
        diff[i - 1] = sensor[i] - sensor[i - 1];
    }

    sort(diff, diff + N - 1, greater<int>());

    for(int i = K - 1; i < N - 1; i++)
        ans += diff[i];

    cout << ans << endl;
    return 0;
}