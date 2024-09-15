#include <iostream>

using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    string str = "";
    string bomb = "";
    string result = "";
    cin >> str;
    cin >> bomb;

    for(int i = 0; i < str.size(); i++) {
        result += str[i];

        if(result.size() >= bomb.size() && result.back() == bomb.back()) {
            bool chk = true;

            for(int j = 0; j < bomb.size(); j++) {
                if(result[result.size() - bomb.size() + j] != bomb[j]) {
                    chk = false;
                    break;
                }
            }

            if(chk) {
                for(int j = 0; j < bomb.size(); j++)
                    result.pop_back();
            }
        }
    }

    if(result.size() > 0)
        cout << result;
    else
        cout << "FRULA";

    return 0;
}
