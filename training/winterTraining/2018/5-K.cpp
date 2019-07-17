#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAX=131072;
int n, q, tmin[MAX+5], tmax[MAX+5], num[MAX+5];
void pushUp(int root){
    tmax[root]=max(tmax[root<<1], tmax[root<<1|1]);
    tmin[root]=min(tmin[root<<1], tmin[root<<1|1]);
}

void build(int l, int r, int root){
    if (l==r){
        tmax[root]=tmin[root]=num[l];
        return ;
    }

    int mid=(l+r)>>1;
    build(l, mid, root<<1);
    build(mid+1, r, root<<1|1);
    pushUp(root);
}

int queryMax(int l, int r, int L, int R, int root){
    if (l<=L && R<=r) return tmax[root];

    int M=(L+R)>>1, ans=0;
    if (l<=M) ans=max(ans, queryMax(l, r, L, M, root<<1));
    if (r>=M+1) ans=max(ans, queryMax(l, r, M+1,R, root<<1|1));
    return ans;
}

int queryMin(int l, int r, int L, int R, int root){
    if (l<=L && R<=r) return tmin[root];

    int M=(L+R)>>1, ans=1000005;
    if (l<=M) ans=min(ans, queryMin(l, r, L, M, root<<1));
    if (r>=M+1) ans=min(ans, queryMin(l, r, M+1,R, root<<1|1));
    return ans;
}

int main(void){
    while (scanf("%d%d", &n, &q)==2){
        for (int i=1; i<=n; i++) scanf("%d", &num[i]);
        build(1, n, 1);

        int a, b;
        while (q--){
            scanf("%d%d", &a, &b);
            printf("%d\n", queryMax(a, b, 1, n, 1) - queryMin(a, b, 1, n, 1));
        }
    }

    return 0;
}
