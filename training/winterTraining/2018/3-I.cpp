#include <cstdio>
int n, prime[50]={0, 0, -1, -1, 0, -1, 0, -1, 0, 0, 0, -1, 0, -1, 0, 0, 0, -1, 0, -1, 0, 0, 0, -1, 0, 0, 0, 0, 0, -1, 0, -1, 0, 0, 0, 0, 0, -1, 0, 0, 0, -1, 0, -1, 0, 0, 0, -1, 0, 0};
void dfs(int idx, int *path, int *vis){
    // it can be optimized.
    if (idx==n) for (int i=0; i<n; i++)
            printf("%d%c", path[i], (i==n-1)?'\n':' ');

    for (int i=2; i<=n; i++){
        if (vis[i]) continue;
        if (!prime[path[idx-1]+i]) continue;
        if (idx==n-1 && !prime[1+i]) continue;
        vis[i]=1; path[idx]=i;
        dfs(idx+1, path, vis);
        vis[i]=0;
    }
}

int main(void){
    for (int kcase=1; scanf("%d", &n)==1; kcase++){
        int path[25]={0}, vis[50]={0};
        path[0]=1; vis[1]=1;
        printf("Case %d:\n", kcase);
        dfs(1, path, vis); printf("\n");
    }

    return 0;
}
