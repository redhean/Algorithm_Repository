#include <iostream>
#include <algorithm>

#define MAX 1001

using namespace std;

int N;
int ans;
int arr[MAX];
int asc[MAX];
int desc[MAX];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> N; 
    for(int i = 0; i < N; i++)
        cin >> arr[i];

    for(int i = 0; i < N; i++) {
        asc[i] = 1;
        for(int j = 0; j < i; j++) {
            if(arr[j] < arr[i]) {
                asc[i] = max(asc[i], asc[j] + 1);
            }
        }
    }

    for(int i = N - 1; i >= 0; i--) {
        desc[i] = 1;
        for(int j = N - 1; j > i; j--) {
            if(arr[j] < arr[i]) {
                desc[i] = max(desc[i], desc[j] + 1);
            }
        }
    }

    for(int i = 0; i < N; i++) {
        ans = max(ans, asc[i] + desc[i]);
    }

    cout << ans - 1 << "\n";

    return 0;
}