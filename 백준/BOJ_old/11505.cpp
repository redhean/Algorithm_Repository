#include <iostream>

#define MAX 1000001
#define MOD 1000000007

using namespace std;

int N, M, K;
long long tree[MAX * 4];

/*long long update(int start, int end, int now, int idx, long long value) {
    if(idx < start || idx > end) {
        return tree[now];
    }

    if(start == end) {
        tree[now] = value;
        return tree[now];
    }
 
    int mid = (start + end) / 2;
    int next = now * 2;

    return tree[now] = (update(start, mid, next, idx, value) * update(mid + 1, end, next + 1, idx, value)) % MOD;
}*/

void update(int start, int end, int now, int idx, int value) {
    if(idx < start || idx > end) {
        return;
    }

    if(start == end) {
        tree[now] = value;
        return;
    }

    int mid = (start + end) / 2;
    int next = now * 2;

    update(start, mid, next, idx, value);
    update(mid + 1, end, next + 1, idx, value);

    tree[now] = (tree[next] * tree[next + 1]) % MOD;
}

long long query(int start, int end, int now, int left, int right) {
    if(right < start || left > end){
        return 1;
    }

    if(start >= left && end <= right){
        return tree[now];
    }

    int mid = (start + end) / 2;
    int next = now * 2;

    return (query(start, mid, next, left, right) * query(mid + 1, end, next + 1, left, right)) % MOD;
}

int main() {    
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> N >> M >> K;

    for(int i = 1; i <= N * 2 + 1; i++) {
        tree[i] = 1;
    }
    
    for(int i = 1; i <= N; i++){
        int a;
        cin >> a;
        update(1, N, 1, i, a);
    }

    for(int i = 0; i < M + K; i++) {
        int a, b;
        long long c;
        cin >> a >> b >> c;

        if(a == 1) {
            update(1, N, 1, b, c);
        }
        else {
            cout << query(1, N, 1, b, c) << '\n';
        }
    }
    return 0;
}

