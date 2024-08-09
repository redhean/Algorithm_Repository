#include <iostream>

#define MAX_N 1001

using namespace std;

int N, M;
int parent[MAX_N];
int ans;

int Find(int a) {
    if(parent[a] == a) return a;
    else return parent[a] = Find(parent[a]);
}

void Union(int a, int b) {
    int aRoot = Find(a);
    int bRoot = Find(b);

    parent[aRoot] = bRoot;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> N >> M;
    for(int i = 1; i <= N; i++) {
        parent[i] = i;
    }

    for(int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;

        Union(a, b);
    }

    
    for(int i = 1; i <= N; i++) {
        if(Find(parent[i]) == i) {
            ans++;
        }
    }

    cout << ans << "\n";

    return 0;
}