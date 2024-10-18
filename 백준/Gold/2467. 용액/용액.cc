#include <iostream>
#include <algorithm>
#include <cmath>

#define MAX 100001

using namespace std;

int N;
int arr[MAX];
int ans[2] = {1000000000, 1000000000};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> N;

    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    int left = 0;
    int right = N - 1;

    while(left < right) {
        int sum = arr[left] + arr[right];
        if(abs(sum) < abs(ans[0] + ans[1])) {
            ans[0] = arr[left];
            ans[1] = arr[right];
        }

        if(sum < 0) {
            left++;
        }
        else if(sum > 0) {
            right--;
        }
        else {
            ans[0] = arr[left];
            ans[1] = arr[right];

            break;
        }
    }

    cout << ans[0] << " " << ans[1] << endl;
    return 0;
}