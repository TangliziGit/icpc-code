#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=2000+200;
const int INF=0x3f3f3f3f;
int val[maxn];

int main(void){
    int T, n;

    scanf("%d", &T);
    while (T--){
        scanf("%d", &n);
        for (int i=1; i<=n-1; i++) scanf("%d", &val[i]);

        int dp[maxn];
        for (int i=0; i<=n-2; i++) dp[i]=-INF;
        dp[0]=n*val[1];
        for (int i=2; i<=n-1; i++){
            for (int j=i-1; j<=n-2; j++)
                dp[j]=max(dp[j], dp[j-i+1]+val[i]-val[1]);
        }
        printf("%d\n", dp[n-2]);
    }

    return 0;
}
