#include <iostream>
#include <algorithm>

#define NMAX 1001
#define MMAX 100001

using namespace std;

int N, M;

struct LanCable {
    int start;
    int end;
    int cost;

    LanCable(){}
    LanCable(int start, int end, int cost) : start(start), end(end), cost(cost){

    }

    bool operator<(const LanCable& cable) const {
        return cost < cable.cost;
    }
};

LanCable lanCable[MMAX];
int parent[NMAX];

int getParent(int a) {
    if(parent[a] == a) return a;
    return parent[a] = getParent(parent[a]);
}

bool isCycle(int a, int b){
    int aRoot = getParent(a);
    int bRoot = getParent(b);

    return aRoot == bRoot;
}

void _union(int a, int b) {
    int aRoot = getParent(a);
    int bRoot = getParent(b);

    parent[aRoot] = bRoot;
}

// 인수로 정점의 수와 간선의 수가 주어진다.
// 여기서는 전역으로 선언해서 넘어감
int kruskal() {
    int mst_cost = 0;
    int selected = 0;

    // 오름차순 정렬
    sort(lanCable, lanCable + M);

    // 간선의 수
    for(int i = 0; i < M; i++) {
        if(!isCycle(lanCable[i].start, lanCable[i].end)){
            mst_cost += lanCable[i].cost;

            selected++;

            _union(lanCable[i].start, lanCable[i].end);
        }
    }
    
    // 간선의 개수가 정점의 n - 1개이면 모두 연결된 것
    if(selected == N - 1){
        return mst_cost;
    }
    else 
        return -1;
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> N >> M;

    for(int i = 0; i < N; i++){
        parent[i] = i;
    }

    for(int i = 0; i < M; i++){
        int start, end, cost;
        cin >> start >> end >> cost;

        lanCable[i] = LanCable(start, end, cost);
    }

    cout << kruskal() << '\n';

    return 0;
}