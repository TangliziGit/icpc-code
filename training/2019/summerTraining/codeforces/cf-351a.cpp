/*
 * 调试过程
 * 1. 最后输出没加fabs
 * 2. 精度过低double解决
 * 3. 数据范围写少了
 * 4. 初始化问题，应为INF
 *
 * */
#include <cmath>
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn=2e3+20, INF=0x3f3f3f3f;
double up[2*maxn], down[2*maxn];
double dp[2*maxn][maxn];
int n;

int main(void){
    double tmp;
    while (scanf("%d", &n)==1){
        for (int i=1; i<=2*n; i++){
            scanf("%lf", &tmp);
            up[i]=tmp-ceil(tmp);
            down[i]=tmp-floor(tmp);
        }

        dp[0][0]=0;
        for (int i=1; i<=2*n; i++) dp[i][0]+=dp[i-1][0]+down[i];
        for (int num=1; num<=n; num++){
            dp[0][num]=INF;
            for (int i=1; i<=2*n; i++){
                double a=dp[i-1][num-1]+up[i], b=dp[i-1][num]+down[i];
                if (fabs(a)<fabs(b)) dp[i][num]=a;
                else dp[i][num]=b;
            }
        }printf("%.3lf\n", fabs(dp[2*n][n]));
    }

    return 0;
}
