#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn=5e5+20;
int fi, la, que[maxn];
int n, m, sum[maxn], dp[maxn];

int gradUp(int i, int j){
    return dp[i]+sum[i]*sum[i]-(dp[j]+sum[j]*sum[j]);
}

int gradDown(int i, int j){
    return sum[i]-sum[j];
}

int update(int i, int j){
    return dp[j]+(sum[i]-sum[j])*(sum[i]-sum[j])+m;
}

int main(void){
    while (scanf("%d%d", &n, &m)==2){
        for (int i=1; i<=n; i++) scanf("%d", &sum[i]);
        sum[0]=dp[0]=0;

        for (int i=1; i<=n; i++) sum[i]+=sum[i-1];
        
        fi=la=0;
        que[la]=0;
        for (int i=1; i<=n; i++){
            while (fi<la && gradUp(que[fi+1], que[fi]) <= 2*sum[i]*gradDown(que[fi+1], que[fi]))
                fi++;
            dp[i]=update(i, que[fi]);
            while (fi<la && gradUp(que[la-1], que[la])*gradDown(que[la], i) >=
                    gradUp(que[la], i)*gradDown(que[la-1], que[la]))
                la--;
            que[++la]=i;
        }
        printf("%d\n", dp[n]);
    }

    return 0;
}
