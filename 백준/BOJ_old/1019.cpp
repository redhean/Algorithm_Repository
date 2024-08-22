#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int N;
vector<int> cnt(10, 0);  // 0~9까지의 숫자 빈도를 저장하는 배열

void countDigits(int N) {
    int factor = 1;           
    int lower = 0, current = 0, higher = 0;
    
    while (N / factor > 0) {
        lower = N - (N / factor) * factor;
        current = (N / factor) % 10;
        higher = N / (factor * 10);
        
        // 현재 자릿수의 숫자보다 낮은 모든 경우의 수를 처리
        for (int i = 0; i < current; i++) {
            if(i == 0)
                cnt[i] += higher * factor;
            else
                cnt[i] += (higher + 1) * factor;
        }
        
        // 현재 자릿수의 숫자에 해당하는 경우의 수를 처리
        cnt[current] += higher * factor + lower + 1;
        
        // 현재 자릿수의 숫자보다 높은 모든 경우의 수를 처리
        for (int i = current + 1; i <= 9; i++) {
            cnt[i] += higher * factor;
        }
        
        // 0의 경우는 따로 처리 (제일 높은 자리수가 0이 되는 경우는 없으므로 제외)
        if (current == 0) {
            cnt[0] -= factor;
        }
        
        factor *= 10;
    }
    
    for (int i = 0; i <= 9; i++) {
        cout << cnt[i] << " ";
    }
    cout << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> N;
    
    countDigits(N);
    
    return 0;
}
