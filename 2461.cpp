#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

vector<pair<int, int>> arr;
int N, M;
long ans = 10000000001;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int temp;
            cin >> temp;
            arr.push_back(make_pair(temp, i));
        }
    }

    sort(arr.begin(), arr.end());  // sort는 기본적으로 first 값을 기준으로 정렬

    int left = 0;
    int right = 0;

    map<int, int> freq;
    int count = 0;

    while (right < N * M) {
        if (freq[arr[right].second] == 0) {
            count++;
        }
        freq[arr[right].second]++;
        right++;

        while (count == N) {
            if (ans > arr[right - 1].first - arr[left].first) {
                ans = arr[right - 1].first - arr[left].first;
            }

            freq[arr[left].second]--;
            if (freq[arr[left].second] == 0) {
                count--;
            }
            left++;
        }
    }

    cout << ans << "\n";

    return 0;
}
