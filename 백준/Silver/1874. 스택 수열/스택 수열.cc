#include <iostream>
#include <stack>

#define MAX_N 100001

using namespace std;

int N;
stack<int> s;
int num[MAX_N];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> num[i];
    }

    int idx = 0;
    string result = "";
    int current = 1; 

    while (current <= N) {
        while (!s.empty() && s.top() == num[idx]) {
            result += "-\n";
            s.pop();
            idx++;
        }

        if (current <= num[idx]) {
            s.push(current);
            result += "+\n";
            current++;
        } else {
            cout << "NO\n";
            return 0;
        }
    }

    while (!s.empty() && s.top() == num[idx]) {
        result += "-\n";
        s.pop();
        idx++;
    }

    if (s.empty()) {
        cout << result;
    } else {
        cout << "NO\n";
    }

    return 0;
}
