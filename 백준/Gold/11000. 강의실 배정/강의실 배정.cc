#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

#define MAX_N 200001

using namespace std;

int N;
priority_queue<int, vector<int>, greater<int>> end_time;
pair<int, int> lecture[MAX_N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for(int i = 0; i < N; i++) {
        int S, T;
        cin >> S >> T;

        lecture[i] = make_pair(S, T);
    }

    sort(lecture, lecture + N);

    for(int i = 0; i < N; i++) {
       if(end_time.empty()) {
            end_time.push(lecture[i].second);
       }
       else {
            if(end_time.top() <= lecture[i].first) {
                end_time.pop();
            }
            end_time.push(lecture[i].second);
       }
    }

    cout << end_time.size() << "\n";

    return 0;
}