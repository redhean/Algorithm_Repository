#include <string>
#include <cstring>
#include <vector>
#include <iostream>

#define MAX 10001

using namespace std;
int arr1[MAX];
int arr2[MAX];

bool chk() {
    int first = 0;
    int second = 0;
    
    for(int i = 0; i < MAX; i++) {
        if(arr1[i] != 0)
            first++;
        
        if(arr2[i] != 0) {
            second++;
        }
    }   
    
    return first == second;
}

int solution(vector<int> topping) {
    int answer = 0;
    
    for(int i = 0; i < topping.size(); i++) {
        arr2[topping[i]]++;
    }
    
    for(int i = 0; i < topping.size(); i++) {
        arr1[topping[i]]++;
        arr2[topping[i]]--;
        
        if(chk())
            answer++;
    }
    
    return answer;
}