#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N;
priority_queue<int, vector<int>, greater<int>> pq;
int cnt;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> N;
    for(int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        pq.push(temp);
    }  

    while(pq.size() > 1) {
        int first = pq.top();
        pq.pop();
        int second = pq.top();
        pq.pop();

        cnt += first + second;
        pq.push(first + second);
    }

    cout << cnt << "\n";

    return 0;
}