#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
long long result;
priority_queue<long long, vector<long long>, greater<long long>> pq;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        long long temp;
        cin >> temp;
        pq.push(temp);
    }

    for(int i = 0; i < m; i++) {
        long long first = pq.top();
        pq.pop();
        long long second = pq.top();
        pq.pop();

        pq.push(first + second);
        pq.push(first + second);
    }

    while(!pq.empty()) {
        result += pq.top();
        pq.pop();
    }

    cout << result << "\n";

    return 0;
}