#include <iostream>
#include <vector>
#include <algorithm>

#define MAX_N 101

using namespace std;

int N, K;
int result;
int product[MAX_N];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> N >> K;

    vector<int> plug;

    for(int i = 0; i < K; i++) {
        cin >> product[i];
    }

    for(int i = 0; i < K; i++) {

        if(find(plug.begin(), plug.end(), product[i]) != plug.end()) {
            continue;
        }

        if(plug.size() < N) {
            plug.push_back(product[i]);
        }
        else {
            int farthest = -1;
            int remove = -1;

            for(int j = 0; j < plug.size(); j++) {
                int temp = 0;

                for(int k = i + 1; k < K; k++) {
                    if(plug[j] == product[k]) {
                        temp = k;
                        break;
                    }
                }

                if(temp == 0) {
                    temp = K;
                }

                if(temp > farthest) {
                    farthest = temp;
                    remove = j;
                }
            }

            plug[remove] = product[i];
            result++;
        }
    }

    cout << result << "\n";

    return 0;
}