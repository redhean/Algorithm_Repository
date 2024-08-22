#include <iostream>
#include <vector>
#include <queue>

#define MAX_N 32001

using namespace std;

int N, M;
vector<int> adj[MAX_N]; // 인접 리스트
int in_degree[MAX_N]; // 진입 차수

void topological_sort() {
    priority_queue<int, vector<int>, greater<int>> pq; // 작은 숫자 우선 큐
    vector<int> result;

    // 진입 차수가 0인 모든 정점을 큐에 삽입
    for (int i = 1; i <= N; i++) {
        if (in_degree[i] == 0) {
            pq.push(i);
        }
    }

    while (!pq.empty()) {
        int curr = pq.top();
        pq.pop();
        result.push_back(curr);

        // 현재 정점의 이웃들을 확인하여 진입 차수를 감소시키고, 새롭게 진입 차수가 0이 된 정점을 큐에 삽입
        for (int neighbor : adj[curr]) {
            in_degree[neighbor]--;
            if (in_degree[neighbor] == 0) {
                pq.push(neighbor);
            }
        }
    }

    // 결과 출력
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;

    // 그래프 구성
    for (int i = 0; i < M; i++) {
        int A, B;
        cin >> A >> B;
        adj[A].push_back(B); // A -> B
        in_degree[B]++; // B의 진입 차수 증가
    }

    // 위상 정렬 수행
    topological_sort();

    return 0;
}
