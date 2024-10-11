#include <string>
#include <vector>
#include <map>
#include <queue>
#include <algorithm> 

using namespace std;

struct Compare {
    bool operator()(const pair<int, string>& a, const pair<int, string>& b) {
        return a.first > b.first; 
    }
};

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    map<string, int> lru;  
    priority_queue<pair<int, string>, vector<pair<int, string>>, Compare> pq; 
    
    if (cacheSize == 0) {
        return cities.size() * 5;
    }

    for (int i = 0; i < cities.size(); i++) {
        transform(cities[i].begin(), cities[i].end(), cities[i].begin(), ::tolower);
        
        if (lru.count(cities[i])) {  
            lru[cities[i]] = i;  
            answer += 1;  
        } else {  
            if (lru.size() >= cacheSize) {  
              
                while (!pq.empty()) {
                    auto top = pq.top();
                    if (lru[top.second] == top.first) {  
                        lru.erase(top.second);
                        pq.pop();
                        break;
                    } else { 
                        pq.pop();
                    }
                }
            }
            lru[cities[i]] = i;  
            answer += 5;  
        }
        pq.push(make_pair(i, cities[i]));
    }

    return answer;
}
