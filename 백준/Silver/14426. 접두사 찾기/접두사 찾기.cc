#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Node {
    char key;
    vector<Node> child;

    Node(char key) : key(key) {}
};

int N, M;
int result;
int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> N >> M;
    vector<Node> child;
    
    Node head = Node('\0'); 

    for(int i = 0; i < N; i++) {
        string temp;
        cin >> temp;

        Node* cur = &head;
        
        for(int j = 0; j < temp.size(); j++) {
            bool found = false;
            
            for(Node& alp : cur->child) {
                if(alp.key == temp[j]) {
                    found = true;
                    cur = &alp;
                    break;
                }
            }

            if(!found) {
                cur->child.push_back(Node(temp[j]));
                cur = &cur->child.back();
            }
        }
    }

    for(int i = 0; i < M; i++) {
        string temp;
        cin >> temp;

        Node* cur = &head;
        bool chk = true;
        for(int j = 0; j < temp.size(); j++) {
            bool found = false;
            
            for(Node& alp : cur->child) {
                if(alp.key == temp[j]) {
                    found = true;
                    cur = &alp;
                    break;
                }
            }

            if(!found) {
                chk = false;
                break;
            }
        }

        if(chk)
            result++;
    }

    cout << result << "\n";

    return 0;
}
