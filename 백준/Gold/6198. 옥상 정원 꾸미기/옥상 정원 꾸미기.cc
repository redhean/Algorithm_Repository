#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int N;
long long result;
stack<int> s;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> N;
    vector<int> height(N);

    for(int i = 0; i < N; i++) {
        cin >> height[i];
    }

    for(int i = 0; i < N; i++) {

        while(!s.empty() && s.top() <= height[i]) {
            s.pop();
        }

        result += s.size();

        s.push(height[i]);
    }

    cout << result << "\n";

    return 0;
}