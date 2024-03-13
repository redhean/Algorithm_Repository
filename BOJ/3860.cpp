#include<cstdio>
#include<algorithm>
#include<vector>
#include<string.h>
#define INF 10000*30*30+1
#define NMAX 900 //30 * 30

using namespace std;

int W,H,G,E;
int dist[NMAX+1]; // 목적지까지의 거리 
int map[NMAX+1]; // 지도 정보 

struct Node {
    int start;
    int end;
    int cost;
    Node(int start, int end, int cost) : start(start), end(end), cost(cost) {
    }
};

vector<Node> adjList;

bool BellmanFord(int V, int start) {

    dist[start] = 0;

    for (int i = 0; i < V - 1; i++) {
        for (Node node : adjList) {
            if (dist[node.start] == INF) continue;
            if (dist[node.end] > dist[node.start] + node.cost) {
                dist[node.end] = dist[node.start] + node.cost;
            }
        }
    }

    bool isNegativeCycle = false;

    for (Node node : adjList) {
        if (dist[node.start] == INF) continue;
        if (dist[node.end] > dist[node.start] + node.cost) {
            isNegativeCycle = true;
            break;
        }
    }

    return isNegativeCycle;

}
int main(){

    while(true){
        scanf(" %d %d",&W,&H);
        if(W==0&&H==0){
            break;
        }

        adjList.clear();
        for(int y=0;y<H;y++){
            for(int x=0;x<W;x++){
                dist[y*W+x]=INF;
                map[y*W+x]=0;
            }
        }

        scanf(" %d",&G);
        for(int i=0;i<G;i++){
            int x, y;
            scanf(" %d %d",&x,&y);
            map[y*W+x] = 1;
        }

        scanf(" %d",&E);
        for(int i=0;i<E;i++){
            int x1,x2,y1,y2,t;
            scanf(" %d %d %d %d %d",&x1,&y1,&x2,&y2,&t);
            int From = y1*W+x1;
            int To = y2*W+x2;
            adjList.push_back(Node(From, To, t));

            map[From] = 2;
        }

        // 각 칸에서 이동할 곳 설정 
        for(int y=0;y<H;y++){
            for(int x=0;x<W;x++){

                int from = y*W+x;
                // 묘비에서 다른칸으로 움직이는 경우는 없다. 
                if(map[from]==1) continue;
                // 귀신 구멍에서는 사방으로 못가고 이동간선은 이미 추가했다. 
                if(map[from]==2) continue;
                // 원문보면 exit 도착하고는 다시 움직이지 않는다
                if(from==W*H-1) continue;

                // 사방으로~ 도착지가 묘비면 갈 수 없다 
                // 동쪽 간선 추가
                if(x<W-1 && map[y*W+x+1]!=1){
                    adjList.push_back(Node(y*W+x, y*W+x+1, 1));
                }
                // 서쪽 간선 추가 
                if(x>0 && map[y*W+x-1]!=1){
                    adjList.push_back(Node(y*W+x, y*W+x-1, 1));
                }
                // 남쪽 간선 추가
                if(y<H-1 && map[(y+1)*W+x]!=1){
                    adjList.push_back(Node(y*W+x, (y+1)*W+x, 1));
                }
                // 북쪽 간선 추가 
                if(y>0 && map[(y-1)*W+x]!=1){
                    adjList.push_back(Node(y*W+x, (y-1)*W+x, 1));
                }
            }
        }

        if (BellmanFord(W*H, 0)) {
            printf("Never\n");
        }else {
            if (dist[W*H-1] == INF){
                printf("Impossible\n");
            }else{
                printf("%d\n", dist[W*H-1]);
            }
        }
    }
}