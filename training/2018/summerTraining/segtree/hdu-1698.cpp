#define intM L+(R-L)/2
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=1e5+20;
int sum[maxn], lazy[maxn], upVal, qL, qR;
struct SegTree{
    SegTree(){clear();}
    void clear(void){
        memset(sum, 0, sizeof(sum));
        memset(lazy, 0, sizeof(lazy));
    }

    void pushdown(int node, int L, int R){
        if (!lazy[node]) return;
        lazy[node*2]=lazy[node];
        lazy[node*2+1]=lazy[node];
        int M=intM;
        sum[node*2]=lazy[node]*(M-L+1);
        sum[node*2+1]=lazy[node]*(R-M);
        lazy[node]=0;
    }

    void update(int node, int L, int R){
        if (qL<=L && R<=qR){
            lazy[node]=upVal;
            sum[node]=upVal*(R-L+1);
        }else{
            pushdown(node, L, R);
            int M=intM;
            if (qL<=M) update(node*2, L, M);
            if (M<qR)  update(node*2+1, M+1, R);
            sum[node]=sum[node*2]+sum[node*2+1];    // pushup
        }
    }

    int query(int node, int L, int R){
        if (qL<=L && R<=qR) return sum[node];
        pushdown(node, L, R);
        int ans=0, M=intM;
        if (qL<=M) ans+=query(node*2, L, M);
        if (M<qR)  ans+=query(node*2+1, M+1, R);
        return ans;
    }
}tree;
int n, m;

int main(void){
    int T, cnt=0;

    scanf("%d", &T);
    while (T--){
        tree.clear();
        scanf("%d%d", &n, &m);
        
        qL=1, qR=n, upVal=1;
        tree.update(1, 1, n);
        while (m--){
            scanf("%d%d%d", &qL, &qR, &upVal);
            tree.update(1, 1, n);
        }
        qL=1, qR=n;
        printf("Case %d: The total value of the hook is %d.\n", ++cnt, tree.query(1, 1, n));
    }

    return 0;
}
