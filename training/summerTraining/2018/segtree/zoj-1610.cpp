// this code will be WA.
// cannot find a map which point to color.

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=8e3+20, maxr=8000;
int n, st[maxn], clr[maxn], ed[maxn], cnt[maxn];
void dfs(int x, int L, int R){
    if (x==-1) return;
    if (L<=ed[x] && st[x]<=R){ // attend to this code
        cnt[clr[x]]++;
        if (ed[x]<R) dfs(x-1, ed[x]+1, R);
        if (st[x]>L) dfs(x-1, L, st[x]-1);
    }else dfs(x-1, L, R);
}

int main(void){
    while (scanf("%d", &n)==1 && n){
        bool vis[maxn]={false};
        for (int i=0; i<n; i++) scanf("%d%d%d", &st[i], &ed[i], &clr[i]), vis[clr[i]]=true;
        dfs(n-1, 0, maxr);
        for (int i=0; i<n; i++) if (vis[i])
            printf("%d %d\n", i, cnt[i]);
        printf("\n");
    }

    return 0;
}
