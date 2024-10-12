#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

#define MAX 50

using namespace std;

int N, M;
int ans = 1e9;  
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
vector<pair<int, int>> chicken;  
vector<pair<int, int>> house;   
vector<int> selected;

int calculate() {
    int totalDistance = 0;

    for (auto h : house) {
        int hx = h.first;
        int hy = h.second;
        int minDist = 1e9;  
        for (int idx : selected) {
            int cx = chicken[idx].first;
            int cy = chicken[idx].second;
            int dist = abs(hx - cx) + abs(hy - cy);  
            minDist = min(minDist, dist);
        }
        totalDistance += minDist;
    }

    return totalDistance;
}

void solve(int start) {
    if (selected.size() == M) {
        ans = min(ans, calculate());
        return;
    }

    for (int i = start; i < chicken.size(); i++) {
        selected.push_back(i);
        solve(i + 1);
        selected.pop_back();
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int temp;
            cin >> temp;
            if (temp == 1) {
                house.push_back({i, j});  
            }
            else if (temp == 2) {
                chicken.push_back({i, j}); 
            }
        }
    }

    solve(0);

    cout << ans << "\n";

    return 0;
}
