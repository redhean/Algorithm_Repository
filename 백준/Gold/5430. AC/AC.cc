#include <iostream>
#include <deque>
#include <string>

using namespace std;

int T;
deque<int> dq;
bool flag;

void read_array(int n, string raw_arr) {
    string temp = "";
    for(int i = 0; i < raw_arr.size(); i++) {
        if(raw_arr[i] == '[' || raw_arr[i] == ']' || raw_arr[i] == ',') {
            if(temp != "") {
                dq.push_back(stoi(temp));
                temp = "";
            }
        }
        else {
            temp += raw_arr[i];
        }
    }
    return;
}

void write_dq() {
    cout << "[";
    int size = dq.size();
    for(int i = 0; i < size; i++) {
        if(flag) {
            cout << dq.back();
            dq.pop_back();
        }
        else {
            cout << dq.front();
            dq.pop_front();
        }
        if(i != size - 1)
            cout << ",";
        }
    cout << "]\n";
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;

    for(int t = 0; t < T; t++) {
        dq.clear();
        flag = false;
        int n;
        string p, arr;
        bool error_flag = false;

        cin >> p;
        cin >> n;
        cin >> arr;
        
        read_array(n, arr);

        for(int i = 0; i < p.size(); i++) {
            if(p[i] == 'R') {
                flag = !flag;
            }
            else {
                if(dq.empty()) {
                    error_flag = true;
                    break;
                }
                if(flag) {
                    dq.pop_back();
                }
                else {
                    dq.pop_front();
                }   
            }
        }

        if(error_flag)
            cout << "error" << "\n";
        else {
            write_dq();
        }
    }

    return 0;
}