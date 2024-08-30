#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
vector<pair<int, int>> meeting;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> N;

    for (int i = 0; i < N; i++) {
        int start, end;
        cin >> start >> end;
        meeting.push_back(make_pair(end, start));
    }

    // 종료 시간을 기준으로 오름차순 정렬
    sort(meeting.begin(), meeting.end());

    int count = 0;
    int last_end_time = 0; // 마지막으로 선택된 회의의 종료 시간

    for (int i = 0; i < N; i++) {
        int cur_start = meeting[i].second;
        int cur_end = meeting[i].first;

        if (cur_start >= last_end_time) {
            count++;
            last_end_time = cur_end;
        }
    }

    cout << count << "\n";
    return 0;
}
