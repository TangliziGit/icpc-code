#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=10+2, maxs=2e6+20, INF=0x3f3f3f3f;
long long cnt[maxn][maxn][maxn], ans[maxn][maxn];
char s[maxs];

void init(void){
    for (int a=0; a<10; a++)
    for (int b=0; b<10; b++)
    for (int c=0; c<10; c++) cnt[a][b][c]=INF;

    for (int a=0; a<10; a++)
    for (int b=0; b<10; b++){
        for (int i=0; i<10; i++)
        for (int j=0; j<10; j++) if (i+j){
            int s=(i*a+j*b)%10;
            cnt[a][b][s]=min(
                cnt[a][b][s], (long long)i+j
            );
        }
    }
}

int main(void){
    init();
    while (scanf("%s", s)==1){
        memset(ans, 0, sizeof(ans));
        for (int i=1; s[i]; i++){
            int diff=(10+s[i]-s[i-1])%10;
            for (int a=0; a<10; a++)
            for (int b=0; b<10; b++){
                if (ans[a][b]==-1 || cnt[a][b][diff]==INF)
                    ans[a][b]=-1;
                else ans[a][b]+=cnt[a][b][diff]-1;
            }
        }

        for (int a=0; a<10; a++)
        for (int b=0; b<10; b++) printf("%lld%c", ans[a][b], " \n"[b==9]);
    }

    return 0;
}
