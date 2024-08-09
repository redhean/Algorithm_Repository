#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int ans;
vector<pair<int, int>> lines;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> N;

    for(int i = 0; i < N; i++) {
        int left;
        int right;

        cin >> left >> right;
        lines.push_back(make_pair(left, right));
    }

    sort(lines.begin(), lines.end());   // 시작 점을 기준으로 오름차순 정렬

    int left = lines[0].first;
    int right = lines[0].second;
    ans += right - left;

    for(int i = 1; i < N; i++) {
        int temp_left = lines[i].first;
        int temp_right = lines[i].second;

        // 포함되는 경우
        if(temp_left <= right && temp_right <= right) {
            continue;
        }
        // 걸치는 경우
        else if(temp_left <= right && temp_right > right) {
            ans += temp_right - right;
            right = temp_right;
        }
        // 안 겹치는 경우
        else if(temp_left > right) {
            ans += temp_right - temp_left;
            left = temp_left;
            right = temp_right;
        }
    }

    cout << ans << "\n";
    return 0;
}