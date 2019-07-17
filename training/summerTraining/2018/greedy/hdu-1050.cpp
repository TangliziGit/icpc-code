#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=200+20;
int n;

int main(void){
    int T, st, ed;

    scanf("%d", &T);
    while (T--){
        scanf("%d", &n);

        int vis[maxn]={0};
        for (int i=0; i<n; i++){
            scanf("%d%d", &st, &ed);
            if (ed%2==0) ed=(ed-1)/2;
            else ed/=2;
            if (st%2==0) st=(st-1)/2;
            else st/=2;
            if (st>ed) swap(st, ed);
            for (int i=st; i<=ed; i++) vis[i]++;
        }

        int ans=0;
        for (int i=0; i<n; i++)
            ans=max(ans, vis[i]);
        printf("%d\n", ans);
    }

    return 0;
}
