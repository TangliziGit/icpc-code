#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn=1e4+20, maxm=5e3+20;
int fi, la, que[maxn];
int dp[maxn][maxm], s[maxn], n, m;

int gradUp(int i, int j, int num){
    return dp[i][num-1]+s[i+1]*s[i+1]-(dp[j][num-1]+s[j+1]*s[j+1]);
}

int gradDown(int i, int j){
    return s[i+1]-s[j+1];
}

int update(int i, int j, int num){
    return dp[j][num-1]+(s[i]-s[j+1])*(s[i]-s[j+1]);
}

int main(void){
    int T, kase=0;
    scanf("%d", &T);
    while (T --> 0){
        scanf("%d%d", &n, &m);
        for (int i=1; i<=n; i++) scanf("%d", &s[i]);
        sort(s+1, s+n+1);

        s[0]=0; dp[0][0]=0;
        for (int i=1; i<=n; i++)
            dp[i][1]=(s[1]-s[i])*(s[1]-s[i]);
        for (int num=2; num<=m; num++){
            dp[0][num]=0;

            fi=la=0;
            que[la]=0;
            for (int i=1; i<=n; i++){
                while (fi<la && gradUp(que[fi+1], que[fi], num) <= 2*s[i]*gradDown(que[fi+1], que[fi]))
                    fi++;
                dp[i][num]=update(i, que[fi], num);

                while (fi<la && gradUp(que[la-1], que[la], num)*gradDown(que[la], i)
                    >=gradUp(que[la], i, num)*gradDown(que[la-1], que[la])) la--;
                que[++la]=i;
            }
        }
        printf("Case %d: %d\n", ++kase, dp[n][m]);
    }

    return 0;
}
