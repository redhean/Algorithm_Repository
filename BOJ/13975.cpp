#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int T;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> T;

    for(int t = 0; t < T; t++) {
        int K;
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        long long cnt = 0;
        cin >> K;

        for(int i = 0; i < K; i++) {
            int temp;
            cin >> temp;
            pq.push(temp);
        }

        while(pq.size() > 1) {
            long long first = pq.top();
            pq.pop();
            long long second = pq.top();
            pq.pop();

            cnt += (first + second);

            pq.push(first + second);
        }
        
        cout << cnt << "\n";
    }

    return 0;
}