#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int N;
stack<pair<int, int>> s;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> N;
    vector<int> height(N);
    vector<int> result(N, 0);

     for(int i = 0; i < N; i++)
        cin >> height[i];

    for(int i = 0; i < N; i++) {
      
        while(!s.empty() && s.top().first <= height[i]) {
            s.pop();
        }

        if(!s.empty()) {
            result[i] = s.top().second;
        }

        s.push(make_pair(height[i], i + 1));

    }

    for(int i = 0; i < N; i++)
        cout << result[i] << " ";

    return 0;
}