#include <cstdio>
#include <cstring>
#include <algorithm>
#define debug(x) printf("## %s = %d\n", #x, x)
using namespace std;
const int maxn=2000+20;
int na, nb, n, choco[maxn], sum;
int dp[maxn], sel[maxn];

void zeroKnap(int cost, int idx){
    for (int wei=na; wei>=cost; wei--)
        if (dp[wei]<dp[wei-cost]+cost){
            dp[wei]=dp[wei-cost]+cost;
            sel[wei]=idx;
        }
}

void show(int x){
    int sta[maxn], siz=0;
    while (x!=0){
        sta[siz++]=sel[x];
        x-=choco[sel[x]];
    }
    printf("%d%c", siz, (siz==0)[" \n"]);
    sort(sta, sta+siz);
    for (int i=0; i<siz; i++)
        printf("%d%c", sta[i]+1, (i==siz-1)[" \n"]);
}

int main(void){
    while (scanf("%d%d", &na, &nb)==2 && (na || nb)){
        scanf("%d", &n); sum=0;
        for (int i=0; i<n; i++) scanf("%d", &choco[i]), sum+=choco[i];

        memset(dp, 0, sizeof(dp));
        memset(sel, -1, sizeof(sel));
        for (int i=0; i<n; i++) zeroKnap(choco[i], i);

        int res;
        for (int i=na; i>=0; i--) if (dp[i]==i){
            res=i; break;
        }

        if (sum-res>nb)
            printf("Impossible to distribute\n");
        else show(res);
    }

    return 0;
}
