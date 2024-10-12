#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> arr;

void dfs(int start) {
    if (arr.size() == M) {
        for (int a : arr) {
            cout << a << " ";
        }
        cout << "\n";
        return;
    }

    for (int i = start; i <= N; i++) {
        arr.push_back(i); 
        dfs(i + 1);            
        arr.pop_back();  
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> N >> M;

    dfs(1); 

    return 0;
}