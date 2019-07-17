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
int n, sx, maxh, data[maxn][2];
int dp(int idx, int pos){
    if (idx==0) return 0;
    if (data[idx][pos]>0) return data[idx][pos];

    int x=(pos)?boards[idx].y:boards[idx].x;
    if (idx==n+1) x=sx;
    for (int i=idx-1; i>0; i--) if (boards[i].x<=x && boards[i].y>=x){
        int dh=boards[idx].hei-boards[i].hei,
            dx=x-boards[i].x, dy=boards[i].y-x;
        if (dh==0) continue;// maybe not useful.
        if (dh>maxh) return data[idx][pos]=INF;
        return data[idx][pos]=min(dp(i, 0)+dx, dp(i, 1)+dy)+dh;
    }return data[idx][pos]=(boards[idx].hei<=maxh)?boards[idx].hei:INF;
}

int main(void){
    int T, sh;

    scanf("%d", &T);
    while (T--){
        scanf("%d%d%d%d", &n, &sx, &sh, &maxh);
        memset(data, -1, sizeof(data));
        boards[0]=Board(-maxp, maxp, 0);
        boards[n+1]=Board(0, 0, sh);
        for (int i=1; i<=n; i++)
            scanf("%d%d%d", &boards[i].x, &boards[i].y, &boards[i].hei);
        sort(boards, boards+n+1);
        printf("%d\n", dp(n+1, 0));
    }

    return 0;
}
