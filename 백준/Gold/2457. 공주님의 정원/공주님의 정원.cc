#include <iostream>
#include <queue>

using namespace std;

int cnt[13] = {0, 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};

struct Node {
    int start;
    int end;

    Node(int start, int end) : start(start), end(end) {

    }

    bool operator<(const Node& a) const {
        if(a.end > cnt[12] && end > cnt[12]) {
            return start > a.start;
        }
        else {
            return end < a.end;
        }
    }
 };

int N;
int ans;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> N;
    priority_queue<Node> pq;

    for(int i = 0; i < N; i++) {
        int sm, sd, em, ed;
        cin >> sm >> sd >> em >> ed;

        pq.push(Node(cnt[sm] + sd, cnt[em] + ed));  
    }

    if(pq.top().end <= cnt[12]) {
        cout << ans << "\n";
        return 0;
    }

    Node cur = pq.top();
    Node temp = pq.top();
    pq.pop();
    ans++;

    while(!pq.empty()) {
        if(cur.start <= cnt[3] + 1) {
            break;
        }

        if(pq.top().end >= cur.start) {
            if(pq.top().start < temp.start) {
                temp = pq.top();
            }
        }
        else {
            if(temp.start != cur.start) {
                ans++;
                cur = temp;
                continue;
            }
        }

        pq.pop();
    }

    if(temp.start != cur.start) {
        ans++;
        cur = temp;
    }

    if(cur.start <= cnt[3] + 1) {
        cout << ans << "\n";
    }
    else {
        cout << 0 << "\n";
    }
    return 0;
}