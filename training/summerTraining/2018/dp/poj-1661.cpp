#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=1000+20, INF=0x3f3f3f3f, maxp=20000;
struct Board{
    int x, y, hei;
    Board(int x=0, int y=0, int hei=0):
        x(x), y(y), hei(hei) {}
    bool operator < (const Board &a) const{
        return hei<a.hei;
    }
}boards[maxn];
int n, sx, maxh;
int data[maxn], dpx[maxn];
int calc(int i, int x, int &xx){
    int minx=INF;
    if (i==n+1 && sx<=boards[x].y && sx>=boards[x].x){
        xx=sx; return 0;
    }

    if ((boards[i].x-1)<=boards[x].y && (boards[i].x-1)>=boards[x].x &&
        minx > dpx[i]-boards[i].x+1){
            minx=dpx[i]-boards[i].x+1;
            xx  =boards[i].x-1;
        }
    if ((boards[i].y+1)<=boards[x].y && (boards[i].y+1)>=boards[x].x && 
        minx > boards[i].y-dpx[i]+1){
            minx=boards[i].y-dpx[i]+1;
            xx  =boards[i].y+1;
        }
    return minx;
}

int dp(int x){
    if (x==n+1) return 0;
    if (x>n+1) return INF;
    if (data[x]>0) return data[x];

    data[x]=INF;
    for (int i=x+1; i<=n+1; i++){
        dp(i);
        int dh=boards[i].hei-boards[x].hei, xx=0,
            dx=calc(i, x, xx);
        printf("%d-%d %d\n", i, x, dx);
        if (dh>maxh) break;
        if (dx>=INF || dh==0) continue;
        if (data[x]>dp(i)+dh+dx){
            data[x]=dp(i)+dh+dx;
            dpx[x] =xx;

            printf("U%d-%d da%d dpx%d\n", i, x, data[x], dpx[x]);
        }
    }return data[x];
}

int main(void){
    int T, sh;

    scanf("%d", &T);
    while (T--){
        scanf("%d%d%d%d", &n, &sx, &sh, &maxh);
        memset(data, -1, sizeof(data));
        boards[0]=Board(-maxp, maxp, 0);
        boards[n+1]=Board(0, 0, sh);
        for (int i=1; i<=n; i++){
            scanf("%d%d%d", &boards[i].x, &boards[i].y, &boards[i].hei);
            if (boards[i].y<boards[i].x) swap(boards[i].y, boards[i].x);
        }
        sort(boards, boards+n);
        for (int i=0; i<=n; i++)
            printf("%d:%d ", i, dp(i));
        printf("\n");
    }

    return 0;
}
