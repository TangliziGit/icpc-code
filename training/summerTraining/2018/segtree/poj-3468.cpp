#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=100000+20;
int n, m;
int qL, qR; long long upVal;
long long sum[maxn*4], lazy[maxn*4];
struct SegTree{
    SegTree(void){clear();}

    void clear(void){
        memset(sum, 0, sizeof(sum));
        memset(lazy, 0, sizeof(lazy));
    }

    void pushdown(int node, int L, int R){
        if (!lazy[node]) return;
        lazy[node*2]+=lazy[node];
        lazy[node*2+1]+=lazy[node];
        int M=L+(R-L)/2;
        sum[node*2]+=lazy[node]*(M-L+1);
        sum[node*2+1]+=lazy[node]*(R-M);
        lazy[node]=0;
    }

    void add(int node, int L, int R){
        if (qL<=L && R<=qR){
            lazy[node]+=upVal;
            sum[node]+=upVal*(R-L+1);
            // this lazy sign should not be cleared.
        }else{
            pushdown(node, L, R);
            int M=L+(R-L)/2;
            if (qL<=M) add(node*2, L, M);
            if (M<qR)  add(node*2+1, M+1, R);
            sum[node]=sum[node*2]+sum[node*2+1]; // pushup(node);
        }
    }

    long long query(int node, int L, int R){
        if (qL<=L && R<=qR) return sum[node];
        pushdown(node, L, R);
        int M=L+(R-L)/2; long long ans=0;
        if (qL<=M) ans+=query(node*2, L, M);
        if (M<qR)  ans+=query(node*2+1, M+1, R);
        return ans;
    }
}tree;

int main(void){
    scanf("%d%d", &n, &m);
    for (int i=1; i<=n; i++){
        scanf("%lld", &upVal); qL=qR=i;
        tree.add(1, 1, n);
    }

    char str[5];
    while (m--){
        scanf("%s%d%d", str, &qL, &qR);
        if (str[0]=='Q') printf("%lld\n", tree.query(1, 1, n));
        else {
            scanf("%lld", &upVal);
            tree.add(1, 1, n);
        }
    }

    return 0;
}
