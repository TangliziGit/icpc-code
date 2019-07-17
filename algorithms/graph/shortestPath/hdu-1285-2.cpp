#include <cstdio>
#include <cstring>
const int maxn=5e2+20;
const long long INF=0x3f3f3f3f;
int n;
long long dist[maxn][maxn];
long long val[maxn];
int prev[maxn][maxn];

void Floyd(void){
    for (int i=0; i<=n; i++)
        dist[i][i]=0, prev[i][i]=i;

    for (int k=1; k<=n; k++)
        for (int i=1; i<=n; i++)
            for (int j=1; j<=n; j++)
                if (val[k]+dist[i][k]+dist[k][j]<dist[i][j]){
                    dist[i][j]=dist[i][k]+dist[k][j]+val[k];
                    prev[i][j]=k;
                }else if (dist[i][k]+dist[k][j]+val[k]==dist[i][j]){
                    if (prev[i][j]>k) prev[i][j]=k;
                }
}

void path(int st, int ed){
    if (prev[st][ed]!=st){
        path(st, prev[st][ed]);
        path(prev[st][ed], ed);
    }else printf("%d-->", st);
}

int main(void){
    while (scanf("%d", &n)==1 && n){
        for (int i=1; i<=n; i++)
            for (int j=1; j<=n; j++){
                scanf("%lld", &dist[i][j]);
                if (dist[i][j]<0) dist[i][j]=INF;
                prev[i][j]=i;
            }
        for (int i=1; i<=n; i++) scanf("%lld", &val[i]);
        
        Floyd();
        int st, ed;
        while (scanf("%d%d", &st, &ed)==2 && st+ed>=0){
            printf("From %d to %d :\n", st, ed);
            printf("Path: ");
            if (st!=ed) path(st, ed);
            printf("%d\n", ed);
            printf("Total cost : %lld\n\n", dist[st][ed]);
        }
    }

    return 0;
}

