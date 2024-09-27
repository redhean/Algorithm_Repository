#include <iostream>
#include <unordered_map>

using namespace std;

string S,E,Q;
unordered_map<string, int> timetable;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> S >> E >> Q;

    string time, name;
    int result = 0;
    while(cin >> time >> name) {
        if(time <= S) {
            timetable[name] = 1;
        }
        else if(time >= E && time <= Q && timetable[name] == 1) {
            timetable[name] = 2;
            result++;
        }
    }

    cout << result << "\n";

    return 0;
}