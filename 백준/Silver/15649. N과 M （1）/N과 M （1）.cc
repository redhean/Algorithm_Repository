#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> arr;
bool visited[10];

void dfs() {
    if (arr.size() == M) {
        for (int a : arr) {
            cout << a << " ";
        }
        cout << "\n";
        return;
    }

    for (int i = 1; i <= N; i++) {
        if (!visited[i]) {  
            visited[i] = true;
            arr.push_back(i); 
            dfs();            
            arr.pop_back();  
            visited[i] = false;
        }
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> N >> M;

    dfs(); 

    return 0;
}