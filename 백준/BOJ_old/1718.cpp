#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int N;
pair<int, int> quiz[200001];

bool compare(const pair<int, int>& a, const pair<int, int>& b) {
    return a.first < b.first;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> N;

    for(int i = 0; i < N; i++) {
        cin >> quiz[i].first >> quiz[i].second;
    }

    // 데드라인 기준으로 정렬 (오름차순)
    sort(quiz, quiz + N, compare);

    // min_heap
    priority_queue<int, vector<int>, greater<int>> pq;
    int ans = 0;

    for(int i = 0; i < N; i++) {
        int deadline = quiz[i].first;
        int ramen = quiz[i].second;

        pq.push(ramen);
        if (pq.size() > deadline) {
            pq.pop();
        }
    }
    
    while (!pq.empty()) {
        ans += pq.top();
        pq.pop();
    }

    cout << ans << "\n";
    return 0;
}
