#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=2e3+20, INF=0x3f3f3f3f;
int n, num[maxn], sorted[maxn], dp[maxn][maxn];
int rnum(int x, bool reverse){
    if (!reverse) return num[x];
    return num[n-x-1];
}

int solve(bool reverse){
    int ans=INF;
    for (int i=0; i<n; i++)
        dp[0][i]=abs(rnum(0, reverse)-sorted[i]);
    for (int i=1; i<n; i++)
        for (int j=0; j<=n; j++){
            if (j!=0) dp[i][j]=min(dp[i][j-1]-abs(rnum(i, reverse)-sorted[j-1]),
                                   dp[i-1][j]);
            else dp[i][j]=dp[i-1][j];
            dp[i][j]+=abs(rnum(i, reverse)-sorted[j]);
        }
    for (int i=0; i<n; i++) ans=min(ans, dp[n-1][i]);
    return ans;
}

int main(void){
    scanf("%d", &n);
    for (int i=0; i<n; i++) scanf("%d", &num[i]), sorted[i]=num[i];
    sort(sorted, sorted+n);
    printf("%d\n", min(solve(false), solve(true)));

    return 0;
}
