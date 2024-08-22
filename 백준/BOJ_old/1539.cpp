#include <iostream>
#include <set>

using namespace std;

int N;
long long ans = 0;
set<pair<int, int>> s;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> N;

    int value;
    cin >> value;
    s.insert(make_pair(value, 1));
    ans += 1;

    for (int i = 1; i < N; i++) {
        cin >> value;

        auto it = s.lower_bound(make_pair(value, 0));
        int newHeight;

        if (it == s.end()) {
            // `value`가 가장 큰 경우, 마지막 요소의 높이를 가져옴
            newHeight = s.rbegin()->second + 1;
        } else if (it == s.begin()) {
            // `value`가 가장 작은 경우
            newHeight = it->second + 1;
        } else {
            // 중간에 삽입되는 경우
            auto prevIt = prev(it);
            newHeight = max(prevIt->second, it->second) + 1;
        }

        s.insert(make_pair(value, newHeight));
        ans += newHeight;
    }

    cout << ans << endl;

    return 0;
}
