#include <cstring>
#include <cstdio>
const int maxn=100;
bool G[maxn+5][maxn+5]={false};

void Floyd(int n){
    for (int k=1; k<=n; k++)
        for (int i=1; i<=n; i++)
            for (int j=1; j<=n; j++)
                G[i][j]=G[i][j] || (G[i][k] && G[k][j]);
}

int main(void){
    int n, m, a, b;

    memset(G, false, sizeof(G));
    scanf("%d%d", &n, &m);
    for (int i=0; i<m; i++){
        scanf("%d%d", &a, &b);
        G[a][b]=true;
    }Floyd(n);

    int ans=0;
    for (int i=1; i<=n; i++){
        int cnt=0;
        for (int j=0; j<=n; j++) if (i!=j && (G[i][j] || G[j][i]))
            cnt++;
        if (cnt==n-1) ans++;
    }printf("%d\n", ans);

    return 0;
}
