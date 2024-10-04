#include <string>
#include <iostream>
#include <set>
#define MAX 11

using namespace std;

int solution(string dirs) {
    int answer = 0;
    int x = 5;
    int y = 5;
    set<string> s;
    
    for(int i = 0; i < dirs.size(); i++) {
        string temp = "";
        string reverse_temp = "";
        
        int prevX = x;
        int prevY = y;

        if(dirs[i] == 'U') {
            if(y - 1 < 0)
                continue;
            y -= 1;
        }
        else if(dirs[i] == 'D') {
            if(y + 1 == MAX)
                continue;
            y += 1;
        }
        else if(dirs[i] == 'R') {
            if(x + 1 == MAX)
                continue;
            x += 1;
        }
        else if(dirs[i] == 'L') {
            if(x - 1 < 0)
                continue;
            x -= 1;
        }

        temp = to_string(min(prevY * MAX + prevX, y * MAX + x)) + "," + to_string(max(prevY * MAX + prevX, y * MAX + x));
        s.insert(temp);
    }

    answer = s.size();
    return answer;
}
