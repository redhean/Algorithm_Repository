#include <vector>
#include <cstdio>
#include <string.h>

#define NMAX 1000000

using namespace std;
typedef long long ll;

int N, M, K;
long long tree[NMAX*3], arr[NMAX+1]; 

void update(int now, int start, int end, int idx, ll value){
    //시작노드(전체범위를 가지는 1 고정), 전체범위 start, 전체범위 end, 업데이트위치 index, 업데이트 값 value
    if( idx < start || end < idx) return; //index가 노드가 가지는 범위를 벗어나면 return 

    tree[now] += value; // index가 범위 안이라면 일단 합산 
    if(start == end) return; // index가 leaf 도착하면 return 

    int mid = ( start + end ) / 2; // 중간값 
    int next = now * 2; // 다음노드 

    update(next, start, mid, idx, value);//왼쪽 자식 , 전체start , 중간값까지 , idx, value 
    update(next + 1, mid + 1, end, idx, value);//오른쪽 자식, 중간값+1, 전체end, idx, value 
}

long long query(int now, int start, int end, int left, int right){
    //시작노드(전체범위를 가지는 1 고정), 전체범위 start, 전체범위 end, 부분합범위 left, 부분합범위 right
    if( right < start || end < left) return 0; // 부분합 범위가 노드가 가지는 범위를 벗어나면 return 

    if( left <= start && end <= right){ //부분합 범위가 노드가 가지는 범위에 완전히 들어오면 
        return tree[now];               //노드에 저장된 합계값을 바로 return 
    };

    if(start == end) return tree[now]; //leaf에 도착하면 노드가 가진 값 가지고 return 

    int mid = ( start + end ) / 2; // 중간값 
    int next = now * 2; // 다음노드 

    //왼쪽 자식 + 오른쪽 자식 합계 리턴 
    return query(next, start, mid, left, right) + query(next + 1, mid + 1, end, left, right);

}

int main() {
    scanf("%d %d %d", &N, &M, &K);

    memset(arr,0,sizeof(arr));
    memset(tree,0,sizeof(tree));

    for(int i=1; i<=N; ++i) {
        scanf("%lld", &arr[i]);
        update(1,1,N,i,arr[i]);
    }

    for(int i=0; i<M+K; ++i) {
        int a;
        scanf("%d", &a);

        if(a == 1) {
            int b;
            ll c;
            scanf("%d %lld", &b, &c);

            ll diff = c - arr[b];
            arr[b] = c;
            //시작노드(전체범위를 가지는 1 고정), 전체범위 start, 전체범위 end, 업데이트위치 index, 업데이트 값 value
            update(1,1,N,b,diff); 
        }else {
            int b, c;
            scanf("%d %d", &b, &c);
            //시작노드(전체범위를 가지는 1 고정), 전체범위 start, 전체범위 end, 부분합범위 left, 부분합범위 right
            printf("%lld\n", query(1,1,N,b,c));
        }
    }
}