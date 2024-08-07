#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int N;
stack<int> s1;
stack<int> s2;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> N;

    vector<int> result(N);

    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        s1.push(temp);
    }

    result[N - 1] = -1;  // 마지막 요소는 항상 -1
    s2.push(s1.top());
    s1.pop();

    for (int i = N - 2; i >= 0; i--) {
        while (!s2.empty() && s1.top() >= s2.top()) {
            s2.pop();
        }

        if (s2.empty()) {
            result[i] = -1;
        } else {
            result[i] = s2.top();
        }

        s2.push(s1.top());
        s1.pop();
    }

    for (int i = 0; i < N; i++) {
        cout << result[i] << " ";
    }

    return 0;
}
