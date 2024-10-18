#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int N, M, L;
int ans;
vector<int> arr;

bool calculate(int mid) {
    int cnt = 0;

    for(int i = 1; i < arr.size(); i++) {
        int dist = arr[i] - arr[i - 1];
        cnt += (dist - 1) / mid;
    }
    return cnt <= M;
} 

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> N >> M >> L;
    arr.push_back(0);
    arr.push_back(L);

    for(int i = 0; i < N; i++) {
        int temp;
        cin >> temp;

        arr.push_back(temp);
    }

    sort(arr.begin(), arr.end());

    int left = 1;
    int right = L;

    while(left <= right) {
        int mid = (left + right) / 2;

        if(calculate(mid)) {
            ans = mid;
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }

    cout << ans << "\n";

    return 0;
}