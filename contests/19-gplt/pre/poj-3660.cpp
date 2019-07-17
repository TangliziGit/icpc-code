#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=120;
int n, m;
bool gra[maxn][maxn];

void floyd(){
    for (int k=1; k<=n; k++)
        for (int i=1; i<=n; i++)
            for (int j=1; j<=n; j++)
                if (gra[i][k]==gra[k][j] && gra[i][k])
                    gra[i][j]=true;
}

int sum(int x){
    int res=0;
    for (int i=1; i<=n; i++)
        res+=gra[x][i]+gra[i][x];
    return res;
}

int main(void){
    int x, y;
    memset(gra, false, sizeof(gra));
    scanf("%d%d", &n, &m);
    for (int i=0; i<m; i++){
        scanf("%d%d", &x, &y);
        gra[x][y]=true;
    }
    floyd();

    int ans=0;
    for (int i=1; i<=n; i++)
        if (sum(i)==n-1) ans++;
    printf("%d\n", ans);

    return 0;
}
