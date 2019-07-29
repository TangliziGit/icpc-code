#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn=1e3+20;
typedef long long LL;
int n, m, fi, la, que[maxn];
LL sum[maxn], cost[maxn], dp[maxn][maxn];

LL X(int i, int n)  {return dp[i][n]+sum[i]*sum[i-1]-cost[i-1];}
LL Y(int i)         {return sum[i];}

LL gradUp(int i, int j)           {return Y(i)-Y(j);}
LL gradDown(int i, int j, int n)  {return X(i, n)-X(j, n);}
LL scost(int a, int b)            {return cost[b]-cost[a-1]-sum[a-1]*(sum[b]-sum[a]);}
LL update(int i, int j, int n)    {return dp[j][n-1]+scost(j+1, i);}

int main(void){
    sum[0]=cost[0]=0;
    while (scanf("%d%d", &n, &m)==2 && n){
        for (int i=1; i<=n; i++){
            scanf("%lld", &sum[i]);
            cost[i]=cost[i-1]+sum[i]*sum[i-1];
            sum[i]+=sum[i-1];
        }

        dp[0][1]=0;
        for (int i=1; i<=n; i++)
            dp[i][1]=scost(1, i);
        for (int num=2; num<=m+1; num++){
            dp[0][num]=0;
            fi=la=0;
            que[la]=0;
            for (int i=1; i<=n; i++){
                while (fi<la && gradUp(que[fi+1], que[fi]) <= sum[i]*gradDown(que[fi+1], que[fi], num-1))
                    fi++;
                dp[i][num]=update(i, que[fi], num);
                while (fi<la && gradUp(que[la], que[la-1])*gradDown(i, que[la], num-1) >=
                        gradUp(i, que[la])*gradDown(que[la], que[la-1], num-1))
                    la--;
                que[--la]=i;
            }
        }
        printf("%lld\n", dp[n][m+1]);
    }

    return 0;
}
