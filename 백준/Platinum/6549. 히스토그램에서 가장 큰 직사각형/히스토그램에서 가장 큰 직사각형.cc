#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int n;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    while(1) {
        cin >> n;

        if(n == 0)
            break;

        stack<int> s;
        vector<int> height(n);
        long long result = 0;

        for(int i = 0; i < n; i++) {
            cin >> height[i];
        }

        for(int i = 0; i < n; i++) {
            while(!s.empty() && height[i] < height[s.top()]) {
                long long top = height[s.top()];

                int pos = i;
                s.pop();

                if(!s.empty())
                    pos = i - s.top() - 1;

                if(result < pos * top)
                    result = pos * top;
            }
            s.push(i);
        }

        while(!s.empty()) {
            long long top = height[s.top()];

                int pos = n;
                s.pop();

                if(!s.empty())
                    pos = n - s.top() - 1;

                if(result < pos * top)
                    result = pos * top;
        }

        cout << result << "\n";
    }

    return 0;
}