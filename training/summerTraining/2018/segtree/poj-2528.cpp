#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=10000+20;
int n, m;
int qL, qR; long long upVal;
long long id[maxn*4], lazy[maxn*4];
struct SegTree{
    SegTree(void){clear();}

    void clear(void){
        memset(id, 0, sizeof(id));
        memset(lazy, 0, sizeof(lazy));
    }

    void pushdown(int node){
        if (!lazy[node]) return;
        lazy[node*2]+=lazy[node];
        lazy[node*2+1]+=lazy[node];
        id[node*2]=lazy[node];
        id[node*2+1]=lazy[node];
        lazy[node]=0;
    }

    void update(int node, int L, int R){
        if (qL<=L && R<=qR){
            lazy[node]=upVal;
            id[node]=upVal;
        }else{
            pushdown(node);
            int M=L+(R-L)/2;
            if (qL<=M) update(node*2, L, M);
            if (M<qR)  update(node*2+1, M+1, R);
            if (id[node*2]==id[node*2+1]) id[node]=id[node*2];
            else id[node]=0;
        }
    }

    long long query(int node, int L, int R){
        if (qL<=L && R<=qR) return id[node];
        pushdown(node);
        int M=L+(R-L)/2; long long ans=0;
        if (qL<=M) ans+=query(node*2, L, M);
        if (M<qR)  ans+=query(node*2+1, M+1, R);
        return ans;
    }
}tree;

struct In{
    int num, idx;
    bool operator < (const In &a) const {
        return num<a.num;
    }
}in[maxn*2];

int main(void){
    int T, inpt;

    scanf("%d", &T);
    while (T--){
        int ans=0;
        tree.clear();
        scanf("%d", &n);
        for (int i=0; i<n; i++){
            scanf("%d%d", &in[i*2].num, &in[i*2+1].num);
            in[i*2].idx=i*2;
            in[i*2+1].idx=i*2+1;
        }
        
        sort(in, in+n*2);
        int size=unique(in, in+2*n)-in;

        for (int i=0; i<2*n; i++){
            
        }
    }

    return 0;
}
