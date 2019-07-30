#include <cstdio>
#include <algorithm>
#define debug(x) printf("%s == %d\n", #x, x)
using namespace std;
const int maxn=1e3+20;
typedef long long LL;
int n, m, fi, la, que[maxn];
LL sum[maxn], cost[maxn], dp[maxn][maxn];

LL Y(int i, int n)  {return dp[i][n]+sum[i]*sum[i+1]-cost[i+1];}
LL X(int i)         {return sum[i];}

LL gradUp(int i, int j, int n)  {return Y(i, n)-Y(j, n);}
LL gradDown(int i, int j)       {return X(i)-X(j);}
LL scost(int a, int b)          {return cost[b]-cost[a]-sum[a-1]*(sum[b]-sum[a]);}
LL update(int i, int j, int n)  {return dp[j][n-1]+scost(j+1, i);}

bool judge(int i, int num){
    LL down=gradDown(que[fi+1], que[fi]);
    if (down>0)
        return gradUp(que[fi+1], que[fi], num-1) <= sum[i]*down;
    return gradUp(que[fi+1], que[fi], num-1) >= sum[i]*down;
}

bool ifUpdate(int i, int num){
    int down1=gradDown(i, que[la]),
        down2=gradDown(que[la], que[la-1]);

    if (down1*down2>0)
        return gradUp(que[la], que[la-1], num-1)*down1 >= gradUp(i, que[la], num-1)*down2;
    return gradUp(que[la], que[la-1], num-1)*down1 <= gradUp(i, que[la], num-1)*down2;
}

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
                while (fi<la && judge(i, num)) fi++;
                dp[i][num]=update(i, que[fi], num);
                while (fi<la && ifUpdate(i, num)) la--;
                que[++la]=i;
            }
        }
        printf("%lld\n", dp[n][m+1]);
    }

    return 0;
}
