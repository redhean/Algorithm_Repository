#include <iostream>

#define MAX 401

using namespace std;

int n, k, s;
int value[MAX][MAX];

void floyd() {
    for(int k = 1; k <= n; k++) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                if(value[i][k] == -1 && value[k][j] == -1) {
                    value[i][j] = -1;
                }
                else if(value[i][k] == 1 && value[k][j] == 1) {
                    value[i][j] = 1;
                }
            }
        }
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> n >> k;

    for(int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;

        value[a][b] = -1;
        value[b][a] = 1;
    }

    floyd();

    cin >> s;

    for(int i = 0; i < s; i++) {
        int a, b;
        cin >> a >> b;

        cout << value[a][b] << "\n";
    }

    return 0;
}