#include <cstdio>
#include <cstring>
const int maxn=1e6+20, INF=0x3f3f3f3f;
int n, m, data[maxn], maxdp[maxn], num[maxn];
int max(int a, int b){
    if (a>b) return a;
    return b;
}

int main(void){
    while (scanf("%d%d", &m, &n)==2 && m){
        memset(data, 0, sizeof(data));
        memset(maxdp, 0, sizeof(maxdp));
        for (int i=1; i<=n; i++) scanf("%d", &num[i]);

        int tmpmax;
        for (int i=0; i<m; i++){
            tmpmax=-INF;
            for (int x=i+1; x<=n; x++){
                data[x]=max(data[x-1]+num[x], maxdp[x-1]+num[x]);
                maxdp[x-1]=tmpmax;
                tmpmax=max(maxdp[x-1], data[x]);
            }
        }
        printf("%d\n", tmpmax);
    }

    return 0;
}
