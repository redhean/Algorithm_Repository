#include <iostream>
#include <algorithm>

#define MAX_N 200001

using namespace std;

int N, C;
int result;
int house[MAX_N];

bool is_possible(int mid) {
    int cnt = 1;    // 맨 처음은 무조건 두고 시작
    int last = house[0];

    for(int i = 1; i < N; i++) {
        if(house[i] - last >= mid) {
            cnt++;
            last = house[i];
        }
    }

    return cnt >= C;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> N >> C;

    for(int i = 0; i < N; i++) {
        cin >> house[i];
    }

    sort(house, house + N);
    
    int low = 1;
    int high = house[N - 1] - house[0];

    while(low <= high) {
        int mid = (low + high) / 2;

        if(is_possible(mid)) {
            result = mid;
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    cout << result << "\n";
    return 0;
}