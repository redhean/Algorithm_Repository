#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 51

using namespace std;

int N;
int ans;
vector<int> positive;
vector<int> negative;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> N;
    
    for(int i = 0; i < N; i++) {
        int temp;
        cin >> temp;

        if(temp <= 0)  {
            negative.push_back(temp);
        }
        else {
            positive.push_back(temp);
        }
    }

    sort(negative.begin(), negative.end(), greater<int>());
    sort(positive.begin(), positive.end());

    while(negative.size() >= 2) {
        int first = negative.back();
        negative.pop_back();
        int second = negative.back();
        negative.pop_back();

        ans += first * second;
    }

    for(int a : negative)
        ans += a;

    while(positive.size() >= 2) {
        int first = positive.back();
        positive.pop_back();
        int second = positive.back();
        positive.pop_back();

        if(first * second > first + second)
            ans += first * second;
        else
            ans += first + second;
    }

    for(int a : positive)
        ans += a;


    cout << ans << "\n";
    return 0;   
}