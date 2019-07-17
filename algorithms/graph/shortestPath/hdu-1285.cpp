#include <cstdio>
#include <string>
#include <cstring>
using namespace std;
const int maxn=5e2+20;
const long long INF=0x3f3f3f3f;
int n;
long long dist[maxn][maxn];
long long val[maxn];
int path[maxn][maxn];

void Floyd(void){
    for (int i=0; i<=n; i++) dist[i][i]=0;

    for (int k=1; k<=n; k++)
        for (int i=1; i<=n; i++)
            for (int j=1; j<=n; j++)
                if (val[k]+dist[i][k]+dist[k][j]<dist[i][j]){
                    dist[i][j]=dist[i][k]+dist[k][j]+val[k];
                    path[i][j]=path[i][k];
                }else if (dist[i][k]+dist[k][j]+val[k]==dist[i][j]){
                    if (path[i][j]>path[i][k]) path[i][j]=path[i][k];
                }
}

void showPath(int st, int ed){
    if (st==ed) {printf("\n"); return;}
    for (int i=path[st][ed]; i!=ed; i=path[i][ed])
        printf("-->%d", i);
    printf("-->%d\n", ed);
}

int main(void){
    while (scanf("%d", &n)==1 && n){
        memset(path, 0, sizeof(path));
        for (int i=1; i<=n; i++)
            for (int j=1; j<=n; j++){
                scanf("%lld", &dist[i][j]);
                if (dist[i][j]<0) dist[i][j]=INF;
                path[i][j]=j;
            }
        for (int i=1; i<=n; i++) scanf("%lld", &val[i]);
        
        Floyd();
        int st, ed;
        while (scanf("%d%d", &st, &ed)==2 && st+ed>=0){
            printf("From %d to %d :\n", st, ed);
            printf("Path: %d", st); showPath(st, ed);
            printf("Total cost : %lld\n\n", dist[st][ed]);
        }
    }

    return 0;
}
