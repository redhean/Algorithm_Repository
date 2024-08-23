#include <iostream>
#include <stack>
#include <map>
#include <vector>

using namespace std;

int N;
long long result;
stack<int> s;
map<int, int> cnt;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> N;
    vector<int> height(N);

    for(int i = 0; i < N; i++) {
        cin >> height[i];
    }

    for(int i = 0; i < N; i++) {
        int out = 0;
        while(!s.empty() && height[i] > s.top()) {
            cnt[s.top()]--;
            s.pop();
            out++;
        }

        if(s.empty()) {
            result += out;
        } 
        else if(height[i] == s.top()) {
            if(cnt[height[i]] < s.size())
                result += cnt[height[i]] + out + 1;
            else
                result += cnt[height[i]] + out;
        }
        else {
            result += (out + 1);
        }

        cnt[height[i]]++;
        s.push(height[i]);
    }

    cout << result << "\n";

    return 0;
}