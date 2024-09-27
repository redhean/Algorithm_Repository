#include <iostream>
#include <unordered_map>

using namespace std;

long long N, P, Q;
unordered_map<long long, long long> m;

long long solution(long long n) {
    if(m.count(n)) {
        return m[n];
    }
    else {
        m[n] = solution(n/P) + solution(n/Q);
        return m[n];
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> P >> Q;

    m[0] = 1;

    cout << solution(N) << "\n";
    
    return 0;
}

