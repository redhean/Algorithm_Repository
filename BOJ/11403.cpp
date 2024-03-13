#include <iostream>

#define MAX 101
#define INF 987654321

using namespace std;

int dist[MAX][MAX];
int N;

void floyd() {
    for(int k = 1; k <= N; k++) {
        for(int i = 1; i <= N; i++) {
            for(int j = 1; j <= N; j++) {
                if(dist[i][k] + dist[k][j] == 2)
                    dist[i][j] = 1;
            }
        }
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> N;
    
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            int a;
            cin >> a;
            dist[i][j] = a;
        }
    }

    floyd();
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            cout << dist[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}