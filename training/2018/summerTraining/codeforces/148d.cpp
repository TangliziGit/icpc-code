#include <cstdio>
#include <cstring>
const int maxn=1e3+20;
double data[maxn][maxn];
bool vis[maxn][maxn];
int nb, nw;
double dp(int i, int j){
    if (i==0 && j==0) return 0;
    if (i<0 || j<0) return 0;
    if (vis[i][j]) return data[i][j];

    vis[i][j]=true;
    double &d=data[i][j];
    if (i+j>=3){
        d=(i/(double)(i+j))*((i-1)/(double)(i+j-1))*((i-2)/(double)(i+j-2))*dp(i-3, j);
        d+=(i/(double)(i+j))*((i-1)/(double)(i+j-1))*(j/(double)(i+j-2))*dp(i-2, j-1);
        d+=j/(long double)(i+j);
    }else if (i+j==2){
        if (i==2) d=0;
        if (j==2) d=1;
        if (i==1) d=0.5;
    }else if (i+j==1){
        if (i==1) d=0;
        if (j==1) d=1;
    }
    return d;
}

int main(void){
    while (scanf("%d%d", &nw, &nb)==2){
        printf("%.9f\n", dp(nb, nw));
    }

    return 0;
}
