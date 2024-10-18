#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

long long solution(vector<int> weights) {
    unordered_map<int, long long> weight_count;
    long long ans = 0;

    for (int weight : weights) {
        weight_count[weight]++;
    }

    for (int weight : weights) {
        weight_count[weight]--;
        
        // 1:1 비율
        ans += weight_count[weight];

        // 2:3 비율
        if (weight % 2 == 0 && weight_count[weight * 3 / 2] > 0) {
            ans += weight_count[weight * 3 / 2];
        }

        // 3:2 비율
        if (weight % 3 == 0 && weight_count[weight * 2 / 3] > 0) {
            ans += weight_count[weight * 2 / 3];
        }

        // 3:4 비율
        if (weight % 3 == 0 && weight_count[weight * 4 / 3] > 0) {
            ans += weight_count[weight * 4 / 3];
        }

        // 4:3 비율
        if (weight % 4 == 0 && weight_count[weight * 3 / 4] > 0) {
            ans += weight_count[weight * 3 / 4];
        }

        // 1:2 비율
        if (weight_count[weight * 2] > 0) {
            ans += weight_count[weight * 2];
        }

        // 2:1 비율
        if (weight % 2 == 0 && weight_count[weight / 2] > 0) {
            ans += weight_count[weight / 2];
        }
    }

    return ans;
}

