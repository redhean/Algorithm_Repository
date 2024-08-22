#include <iostream>
#include <algorithm>
#include <vector>

#define MAX 51
#define INF 987654321

using namespace std;

int N;
int dist[MAX][MAX];
vector<pair<int,int>> result;

void floyd() {
    for(int k = 1; k <= N; k++) {
        for(int i = 1; i <= N; i++) {
            for(int j = 1; j <= N; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> N;

    for(int i = 0; i < MAX; i++) {
        for(int j = 0; j < MAX; j++) {
            if(i == j)
                dist[i][j] = 0;
            else
                dist[i][j] = INF;
        }
    }

    int first, second;
    while(1) {
        cin >> first >> second;
        if(first == -1 && second == -1)
            break;

        dist[first][second] = 1;
        dist[second][first] = 1;
    }

    floyd();

    int min = INF;
    for(int i = 1; i <= N; i++) {
        int max = 0;
        for(int j = 1; j <= N; j++){
            if(dist[i][j] > max)
                max = dist[i][j];
        }
        result.push_back(make_pair(max, i));

        if(max < min)
            min = max;
    }

    sort(result.begin(), result.end());
    
    int cnt = 0;
    for(int i = 0; i < N; i++){
        if(result[i].first == min)
            cnt++;
        else
            break;
    }

    cout << min << " " << cnt << '\n';

    for(int i = 0; i < cnt; i++){
        if(result[i].first == min)
            cout << result[i].second << " ";
    }
    return 0;
}