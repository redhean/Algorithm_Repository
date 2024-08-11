#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
vector<int> student;
long long cnt;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> N;

    for(int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        student.push_back(temp);
    }

    sort(student.begin(), student.end());

    for(int i = 0; i < N - 2; i++) {
        for(int j = i + 1; j < N - 1; j++) {
            int target = (student[i] + student[j]) * -1;
    
            auto lower = lower_bound(student.begin() + j + 1, student.end(), target);
        
            auto upper = upper_bound(student.begin() + j + 1, student.end(), target);
        
            if (lower != student.end() && *lower == target) {
                cnt += distance(lower, upper);
            }
        }
    }


    cout << cnt << "\n";
    return 0;
}