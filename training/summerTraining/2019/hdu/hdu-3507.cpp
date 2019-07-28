// wrong answer 
// 问题在于是否允许dp[i]=update(0, i)
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long LL;
const int maxn=5e5+20, maxm=1e3+20;
int fi, la, que[maxn], n, m;
LL c[maxn], sum[maxn], dp[maxn];

LL gradUp(int i, int j){
    return dp[i]+sum[i]*sum[i]-(dp[j]+sum[j]*sum[j]);
}

LL gradDown(int i, int j){
    return sum[i]-sum[j];
}

LL update(int j, int i){
    return dp[j]+(sum[i]-sum[j])*(sum[i]-sum[j])+m;
}

int main(void){
    while (scanf("%d%d", &n, &m)==2){
        for (int i=0; i<n; i++) scanf("%lld", &c[i]);

        sum[0]=c[0];
        for (int i=1; i<n; i++) sum[i]=sum[i-1]+c[i];

        dp[0]=sum[0]*sum[0]+m;
        fi=la=0;
        que[fi]=0;
        for (int i=1; i<n; i++){
            while (fi<la && gradUp(que[fi], que[fi+1]) >= 2*sum[i]*gradDown(que[fi], que[fi+1]))
                fi++;
            dp[i]=update(que[fi], i);
            while (fi<la && gradUp(que[la-1], que[la])*gradDown(que[la], i) <=
                    gradUp(que[la], i)*gradDown(que[la-1], que[la]))
                la--;
            que[++la]=i;
        }printf("%lld\n", dp[n-1]);
    }

    return 0;
}
