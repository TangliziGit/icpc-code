// POJ-1502
// to get minumum distance[a][b] from a to b, despite of negtive dis
//
// Description:
// use dp to get minimum dis
//
// Details:
// 1. initialize dis (dis[i][i]=0, else dis=INF)

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int VerMax=105, INF=0x3f3f3f3f;
int n, dist[VerMax+5][VerMax+5];
int Floyd(void){
    int ans=0;
    for (int k=1; k<=n; k++)
        for (int i=1; i<=n; i++)
            for (int j=1; j<=n; j++)
                if (dist[i][k]<INF && dist[k][j]<INF)
                    dist[i][j]=min(dist[i][j], dist[i][k]+dist[k][j]);
    for (int i=2; i<=n; i++)
        ans=max(ans, dist[1][i]);
    return ans;
}

int main(void){
    char str[25];
    scanf("%d", &n);
    memset(dist, INF, sizeof(dist));
    for (int i=2; i<=n; i++)
        for (int j=1; j<i; j++){
            scanf("%s", str);
            if (str[0]=='x') continue;
            dist[i][j]=dist[j][i]=atoi(str);
        }
    printf("%d\n", Floyd());

    return 0;
}
