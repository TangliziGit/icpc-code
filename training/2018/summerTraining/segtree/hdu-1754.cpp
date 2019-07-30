#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=200000, INF=0x3f3f3f3f;
int n, m;

int queR, queL, upVal, upPos;
long long maxVal[maxn*4];
struct SegTree{
    SegTree(void){
        memset(maxVal, 0, sizeof(maxVal));
    }

    void update(int node, int L, int R){
        if (L==R) maxVal[node]=upVal;
        else {
            int M=L+(R-L)/2;
            if (upPos<=M) update(node*2, L, M);
            else update(node*2+1, M+1, R);
            maxVal[node]=max(maxVal[node*2], maxVal[node*2+1]);
        }
    }

    long long query(int node, int L, int R){
        if (queL<=L && R<=queR) return maxVal[node];
        else {
            int M=L+(R-L)/2; long long ans=-INF;
            if (queL<=M) ans=max(ans, query(node*2, L, M));
            if (M<queR)  ans=max(ans, query(node*2+1, M+1, R));
            return ans;
        }
    }
};

int main(void){
    SegTree tree;

    while (scanf("%d%d", &n, &m)==2 && n){
        for (upPos=1; upPos<=n; upPos++){
            scanf("%d", &upVal);
            tree.update(1, 1, n);
        }

        char cmd[5]; long long arg[2];
        while (m--){
            scanf("%s%lld%lld", cmd, &arg[0], &arg[1]);
            if (cmd[0]=='U'){
                upPos=arg[0]; upVal=arg[1];
                tree.update(1, 1, n);
            }else{
                queL=arg[0]; queR=arg[1];
                printf("%lld\n", tree.query(1, 1, n));
            }
        }
    }

    return 0;
}
