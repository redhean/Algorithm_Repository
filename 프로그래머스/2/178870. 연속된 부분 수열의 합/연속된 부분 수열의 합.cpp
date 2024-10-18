#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer(2);
    answer[0] = 0;
    answer[1] = sequence.size() - 1;
    
    int left = 0;
    int right = 0;
    int sum = sequence[0];
    
    while(right < sequence.size()) {
        if(sum < k) {
            sum += sequence[++right];
        }
        else if(sum > k) {
            sum -= sequence[left++];
        }
        else {
            if(right - left < answer[1] - answer[0]) {
                answer[0] = left;
                answer[1] = right;
            }
            
            sum += sequence[++right];
        }
    }
    
    return answer;
}