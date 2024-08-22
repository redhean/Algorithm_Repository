#include <iostream>
#include <algorithm>
#include <vector>

#define MAX_N 1001

using namespace std;

int N;
int  arr[MAX_N];
vector<int> two;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> N;

    for(int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        arr[i] = temp;
    }  

    for(int i = 0; i < N; i++) {
        for(int j = i; j < N; j++) {
            two.push_back(arr[i] + arr[j]);
        }
    }

    sort(arr, arr + N);
    sort(two.begin(), two.end());

    for(int i = N - 1; i >= 0; i--) {
        for(int j = i; j >= 0; j--) {
            int target = arr[i] - arr[j];
            bool exist = binary_search(two.begin(), two.end(), target);

            if(exist) {
                 cout << arr[i] << "\n";
                 return 0;
            }
        }
    }
    return 0;
}