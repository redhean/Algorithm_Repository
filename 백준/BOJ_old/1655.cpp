#include <iostream>
#include <queue>

using namespace std;

int N;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    priority_queue<int, vector<int>> max_heap;
    priority_queue<int, vector<int>, greater<int>> min_heap;
    cin >> N;

    for(int i = 0; i < N; i++){
        int temp;
        cin >> temp;

        max_heap.push(temp);
        if(min_heap.size() > 0 && temp > min_heap.top()){   // 새로 들어온 값이 min_heap의 top 보다 클 때
                max_heap.push(min_heap.top());
                min_heap.pop();
                min_heap.push(max_heap.top());
                max_heap.pop();
        }

        if(max_heap.size() - min_heap.size() >= 2){
            min_heap.push(max_heap.top());
            max_heap.pop();
        }

        cout << max_heap.top() << '\n';
    }

    return 0;
}