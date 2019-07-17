#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=50000+20;
int n;
int upVal, upPos, queL, queR, sum[maxn*3];
struct SegTree{
    // all segment arguments means [L, R], it's closed interval.
    SegTree(void){clear();}

    void clear(void){
        memset(sum, 0, sizeof(sum));
    }

    void add(int node, int L, int R){
        // node     means the current node index,
        // [L, R]   means the interval under this node's control.
        if (L==R) sum[node]+=upVal;
        else{
            int M=L+(R-L)/2;
            if (upPos<=M) add(node*2, L, M);
            else add(node*2+1, M+1, R);
            sum[node]=sum[node*2]+sum[node*2+1];
        }
    }

    int query(int node, int L, int R){
        // node     means the current node index,
        // [L, R]   means the interval under this node's control.
        if (queL<=L && R<=queR) return sum[node];
        else{
            int M=L+(R-L)/2, ans=0;
            if (queL<=M) ans+=query(node*2, L, M);
            if (M<queR)  ans+=query(node*2+1, M+1, R);
            return ans;
        }
    }
};

int main(void){
    int T, cnt=0;
    SegTree tree;

    scanf("%d", &T);
    while (T--){
        tree.clear();
        scanf("%d", &n);
        for (upPos=1; upPos<=n; upPos++){
            scanf("%d", &upVal);
            tree.add(1, 1, n);
        }

        printf("Case %d:\n", ++cnt);
        char cmd[10]; int arg[2];
        while (scanf("%s", cmd)==1 && cmd[0]!='E'){
            scanf("%d%d", &arg[0], &arg[1]);
            if (cmd[0]=='A'){
                upPos=arg[0]; upVal=arg[1];
                tree.add(1, 1, n);
            }else if (cmd[0]=='S'){
                upPos=arg[0]; upVal=-arg[1];
                tree.add(1, 1, n);
            }else{
                queL=arg[0]; queR=arg[1];
                printf("%d\n", tree.query(1, 1, n));
            }
        }
    }

    return 0;
}
