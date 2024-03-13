#include <vector>
#include <cstdio>
#include <string.h>

#define NMAX 1000000

using namespace std;
typedef long long ll;

int N, M, K, start;
long long tree[NMAX*3];

void update(int idx, ll value) {
    // idx : 업데이트 위치, value : 업데이트 될 값
    idx = idx + start;
    tree[idx] = value;
    // 절반으로 나누면 부모위치이므로 Root 까지 반으로 나누며 올라간다.
    for (int p = idx / 2; p > 0; p = p / 2) {
        tree[p] = tree[p * 2] + tree[p * 2 + 1];
    }
}

long long get(int left, int right) {
    long long sum = 0;
    left = left + start; // tree 배열의 인덱스로 변환
    right = right + start; // tree 배열의 인덱스로 변환

    while (left <= right) {
        if (left % 2 == 1) { // Left 가 홀수이면 ( 즉 left 가 오른쪽 자식이면 )
            sum = sum + tree[left]; // 바꾸고 한칸 오른쪽으로
            left = left + 1;
        }
        if (right % 2 == 0) { // Right 가 짝수이면 ( 즉 right 가 왼쪽 자식이면 )
            sum = sum + tree[right]; // 바꾸고 한칸 왼쪽으로
            right = right - 1;
        }

        left = left / 2;
        right = right / 2;
    }
    return sum;
}

int main() {
    scanf("%d %d %d", &N, &M, &K);

    int treesize = 1; // 노드크기를 확인하기 위한 초기화 

    while (treesize < N){
        // 노드가 전부 들어갈 수 있는 크기를 찾는다. 
        treesize = treesize * 2;
    }

    memset(tree,0,treesize * 2 + 1);
    start = treesize - 1; // 트리 인덱스를 찾기위한 값 

    for(int i=1; i<=N; ++i) {
        ll inp;
        scanf("%lld", &inp);
        tree[start + i] = inp;
    }// leaf 영역 채우기 

    for (int i = start; i != 0; i--) {
        tree[i] = tree[i * 2] + tree[i * 2 + 1];
    }// leaf 제외한 영역 채우기

    for(int i=0; i<M+K; ++i) {
        int a;
        scanf("%d", &a);

        if(a == 1) {
            int b;
            ll c;
            scanf("%d %lld", &b, &c);
            update(b, c);
        }else {
            int b, c;
            scanf("%d %d", &b, &c);
            printf("%lld\n", get(b, c));
        }
    }
}