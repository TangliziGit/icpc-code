#include <cstdio>
// it is the 3 time to write this problem
// but forget the great codes again :(
int n, k;
char chess[10][10];
int dfs(int y, int rest, int vis[]){
    if (rest==0) return 1;
    if (y>=n) return 0;

    int cnt=0;
    for (int i=0; i<n; i++){
        if (vis[i] || chess[y][i]=='.') continue;

        vis[i]=1;
        cnt+=dfs(y+1, rest-1, vis);
        vis[i]=0;
    }return cnt+dfs(y+1, rest, vis); // the codes
}


int main(void){
    while (scanf("%d%d", &n, &k)==2 && n!=-1){
        int vis[10]={0};
        for (int y=0; y<n; y++) scanf("%s", chess[y]);
        printf("%d\n", dfs(0, k, vis));
    }

    return 0;
}