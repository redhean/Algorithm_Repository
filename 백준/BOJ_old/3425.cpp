#include <iostream>
#include <stack>
#include <vector>
#include <cmath>
#include <string>

#define MAX 1000000000
#define ll long long

using namespace std;

vector<string> command;

int main() { 
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    stack<ll> stack;
    vector<ll> num_com;
    string com = "start";
    int n;
    ll num;
    int num_cnt = 0;

    while(1){
        int chk = 0;
        command.clear();
        num_com.clear();

        while(1) {
            cin >> com;
            if(com == "NUM"){
                ll temp_num;
                cin >> temp_num;
                num_com.emplace_back(temp_num);
                num_cnt++;
            }
            
            if(com != "END")
                command.emplace_back(com);
            else
                break;
            
            if(com == "QUIT"){
                chk = 1;
                break;
            }
        }

        if(chk)
            break;

        cin >> n;
        for(int i = 0; i < n; i++) {
            int num_cnt2 = 0;
            int err = 0;
            cin >> num;
            stack.push(num);

            for(int j = 0; j < command.size(); j++){
                if(command[j] == "NUM") {
                    if(num_cnt2 >= num_cnt){
                        err = 1;
                        break;
                    }

                    stack.push(num_com[num_cnt2]);
                    num_cnt2++;
                }
                else if(command[j] == "POP") {
                    if(!stack.empty())
                        stack.pop();
                    else{
                        err = 1;
                        break;
                    }
                }
                else if(command[j] == "INV") {
                    if(!stack.empty()){
                        ll temp = stack.top();
                        stack.pop();
                        stack.push(temp * -1);
                    }
                    else{
                        err = 1;
                        break;
                    }  
                }
                else if(command[j] == "DUP") {
                    if(!stack.empty()){
                        ll temp = stack.top();
                        stack.push(temp);
                    }
                    else{
                        err = 1;
                        break;
                    }
                }
                else if(command[j] == "SWP") {
                    if(stack.size() < 2){
                        err = 1;
                        break;
                    }

                    ll first = stack.top();
                    stack.pop();
                    ll second = stack.top();
                    stack.pop();
                    stack.push(first);
                    stack.push(second);
                }
                else if(command[j] == "ADD") {
                    if(stack.size() < 2){
                        err = 1;
                        break;
                    }

                    ll first = stack.top();
                    stack.pop();
                    ll second = stack.top();
                    stack.pop();

                    if(abs(first + second) > MAX){
                        err = 1;
                        break;
                    }
                    else 
                        stack.push(first + second);
                }   
                else if(command[j] == "SUB") {
                    if(stack.size() < 2){
                        err = 1;
                        break;
                    }

                    ll first = stack.top();
                    stack.pop();
                    ll second = stack.top();
                    stack.pop();
                    if(abs(second - first) > MAX){
                        err = 1;
                        break;
                    }
                    else 
                        stack.push(second - first);
                }
                else if(command[j] == "MUL") {
                    if(stack.size() < 2){
                        err = 1;
                        break;
                    }

                    ll first = stack.top();
                    stack.pop();
                    ll second = stack.top();
                    stack.pop();
                    if(abs(first * second) > MAX){
                        err = 1;
                        break;
                    }
                    else 
                        stack.push(first * second);
                }
                else if(command[j] == "DIV") {
                    if(stack.size() < 2){
                        err = 1;
                        break;
                    }

                    if(stack.empty()){
                        err = 1;
                        break;
                    }

                    if(stack.top() == 0){
                        err = 1;
                        break;
                    }

                    ll first = stack.top();
                    stack.pop();
                    ll second = stack.top();
                    stack.pop();
                    int negative_cnt = 0;
                        
                    if(first < 0){
                        negative_cnt++;
                        first *= -1;
                    }
                    if(second < 0){
                        negative_cnt++;
                        second *= -1;
                    }

                    if(negative_cnt == 1){
                        stack.push((second / first) * -1);
                    }
                    else
                        stack.push(second / first);
                }
                else if(command[j] == "MOD") {
                    if(stack.size() < 2){
                        err = 1;
                        break;
                    }

                    if(stack.empty()){
                        err = 1;
                        break;
                    }

                    if(stack.top() == 0){
                        err = 1;
                        break;
                    }

                    ll first = stack.top();
                    stack.pop();
                    ll second = stack.top();
                    stack.pop();

                    if(second < 0) {
                        stack.push((abs(second) % abs(first))* -1);
                    }
                    else{
                        stack.push(abs(second) % abs(first));
                    }
                }
            }
                
            if(stack.size() != 1 || err){
                cout << "ERROR" << '\n';
                while(!stack.empty()){
                    stack.pop();
                }
            }
            else{
                cout << stack.top() << '\n';
                stack.pop();
            }
        }

        cout << '\n';
    }

    return 0;
}