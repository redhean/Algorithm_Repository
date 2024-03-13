#include <iostream>
#include <algorithm>
#include <cstring>

#define MAX 100001
#define INF 1000000001

using namespace std;

int N, M;
int tree[MAX * 4 + 4];

void update(int start, int end, int now, int idx, int value) {
    if(idx < start || idx > end){
        return;
    }

    if(start == end){
        tree[now] = value;
        return;
    }

    tree[now] = min(tree[now], value);

    int mid = (start + end) / 2;
    int next = now * 2;

    update(start, mid, next, idx, value);
    update(mid + 1, end, next + 1, idx, value);
}

int query(int start, int end, int now, int left, int right) {
    if(left > end || right < start) {
        return INF;
    }

    if(start >= left && end <= right)
        return tree[now];

    int mid = (start + end) / 2;
    int next = now * 2;

    return min(query(start, mid, next, left, right), query(mid + 1, end, next + 1, left, right));
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> N >> M;

    for(int i = 1; i <= N * 2 + 1; i++)
        tree[i] = INF;

    for(int i = 1; i <= N; i++) {
        int a;
        cin >> a;
        update(1, N, 1, i, a);
    }

    for(int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        cout << query(1, N, 1, a, b) << '\n';
    }

    return 0;
}