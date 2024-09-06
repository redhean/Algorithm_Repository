#include <iostream>
#include <vector>

using namespace std;

int T;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> T;

    for (int t = 0; t < T; t++) {
        long long result = 0;
        int N;
        cin >> N;

        vector<int> price(N);
        for (int i = 0; i < N; i++) {
            cin >> price[i];
        }

        int maxPrice = price[N-1];
        for (int i = N - 2; i >= 0; i--) {
            if (price[i] < maxPrice) {
                result += maxPrice - price[i];
            } 
            else {
                maxPrice = price[i];
            }
        }

        cout << result << "\n";
    }

    return 0;
}
