#include <cstdio>
#include <cstring>
#define lowbit(x) ((x)&(-x))
const int XMAX=32000;
int n, stars[XMAX+5];
int sum(int x, int y){
    int result=0;
    for (int i=y; i>0; i-=lowbit(i))
        for (int j=x; j>0; j-=lowbit(j))
        result+=stars[i][j];
    return result;
}

void add(int x){
    for (int i=y; i<=XMAX+1; i+=lowbit(i))
        for (int j=x; j<=XMAX+1; j+=lowbit(j))
            stars[i][j]++;
}

int getsum(int ux, int uy, int dx, int dy){
    return sum(ux, uy)-sum(dx, uy)-sum(ux, dy)+sum(dx, dy);
}

int main(void){
    while (scanf("%d", &n)==1){
        int level[15000+5]={0};
        memset(stars, 0, sizeof(stars));
        for (int i=0, x, y; i<n; i++){
            scanf("%d%d", &x, &y);
            add(x+1, y+1);
        }
        for (int i=0; i<n; i++) printf("%d\n", level[i]);
    }

    return 0;
}
