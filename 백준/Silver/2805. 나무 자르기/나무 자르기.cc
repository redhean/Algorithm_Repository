#include <iostream>
#include <vector>
#include <algorithm>

#define MAX_N 1000001

using namespace std;

int N, M;
int tree[MAX_N];

bool is_possible(long long mid) {
    long long cur = 0;

    for(int i = 0; i < N; i++) {
        if(tree[i] > mid) {
            cur += (tree[i] - mid);
            if(cur >= M)
                return true;
        }
    }
    return false;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> N >> M;

    for(int i = 0; i < N; i++) {
        cin >> tree[i];
    }

    sort(tree, tree + N);

    long long low = 0;
    long long high = tree[N - 1];
    long long result = 0;

    while(low <= high) {
        long long mid = (low + high) / 2;

        if(is_possible(mid)) {
            result = mid;
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    cout << result << "\n";
    return 0;   
}