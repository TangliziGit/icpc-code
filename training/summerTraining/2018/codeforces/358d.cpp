#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=3e3+20;
int dp[maxn][4], a[maxn], b[maxn], c[maxn];
int n;

int main(void){
    while (scanf("%d", &n)==1){
        for (int i=1; i<=n; i++) scanf("%d", &a[i]);
        for (int i=1; i<=n; i++) scanf("%d", &b[i]);
        for (int i=1; i<=n; i++) scanf("%d", &c[i]);

        if (n==1){
            printf("%d\n", a[1]);
            continue;
        }
        dp[n-1][0]=a[n-1]+b[n];
        dp[n-1][1]=b[n-1]+b[n];
        dp[n-1][2]=b[n-1]+a[n];
        dp[n-1][3]=c[n-1]+a[n];
        for (int i=n-2; i>=1; i--){
            dp[i][0]=max(dp[i+1][1], dp[i+1][3])+a[i];
            dp[i][1]=max(dp[i+1][1], dp[i+1][3])+b[i];
            dp[i][2]=max(dp[i+1][0], dp[i+1][2])+b[i];
            dp[i][3]=max(dp[i+1][0], dp[i+1][2])+c[i];
        }
        int ans=max(dp[1][0], dp[1][2]);
        printf("%d\n", ans);
    }

    return 0;
}
