#include <iostream>
#include <stack>

using namespace std;

int ans;
int N;
stack<int> s;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> N;

    for(int i = 0; i < N; i++) {
        int num;
        cin >> num;

        if(num != 0)
            s.push(num);
        else
            s.pop();
    }

    while(!s.empty()) {
        ans += s.top();
        s.pop();
    }

    cout << ans << "\n";

    return 0;
}