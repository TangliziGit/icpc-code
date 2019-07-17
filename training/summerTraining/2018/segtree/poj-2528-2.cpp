#include <cstdio>
#include <cstring>
const int maxn=1e4+20, maxr=10000000;
bool vis[maxn];
int st[maxn], end[maxn];
int dfs(int x, int l, int r){
    if (x==-1) return 0;
    if (st[x]<=r && end[x]>=l){
        int ans=0;
        if (!vis[x]) vis[x]=true, ans++;
        if (st[x]>l) ans+=dfs(x-1, l, st[x]-1);
        if (r>end[x]) ans+=dfs(x-1, end[x]+1, r);
        return ans;
    }else return dfs(x-1, l, r);
}

int main(void){
    int T, n;
    scanf("%d", &T);
    while (T--){
        scanf("%d", &n);
        memset(vis, false, sizeof(vis));
        for (int i=0; i<n; i++) scanf("%d%d", &st[i], &end[i]);
        printf("%d\n", dfs(n-1, 0, maxr));
    }

    return 0;
}
