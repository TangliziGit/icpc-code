#include <map>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
const int tmax = 12500000;
int a[10];
int vis[tmax*2 + 1];

int main(void) {
    while (scanf("%d%d%d%d%d", &a[0], &a[1], &a[2], &a[3], &a[4]) == 5) {
        memset(vis, 0, sizeof(vis));
        for (LL x2=-50; x2<=50; x2++) {
            if (x2 == 0) continue;
            for (LL x3=-50; x3<=50; x3++) {
                if (x3 == 0) continue;

                LL ans = a[3]*x2*x2*x2 + a[4]*x3*x3*x3;
                vis[tmax-ans]++;
            }
        }

        int cnt = 0;
        for (LL x1=-50; x1<=50; x1++) {
            if (x1 == 0) continue;
            for (LL x2=-50; x2<=50; x2++) {
                if (x2 == 0) continue;
                for (LL x3=-50; x3<=50; x3++) {
                    if (x3 == 0) continue;

                    LL ans = a[0]*x1*x1*x1 + a[1]*x2*x2*x2 + a[2]*x3*x3*x3 + tmax;
                    if (ans < 0 || ans >= 2*tmax + 1) continue;
                    cnt += vis[ans];
                }
            }
        }

        printf("%d\n", cnt);
    }

    return 0;
}
