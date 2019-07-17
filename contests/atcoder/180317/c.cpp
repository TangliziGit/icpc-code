#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=200;
struct Point{
    int x, y;
    Point(int x=0, int y=0):x(x), y(y) {}
    bool operator < (const Point &a) const{
        return y<a.y;
    }
}point[maxn+5];
int n;
bool map[maxn+5][maxn+5];

int main(void){
    scanf("%d", &n);
    for (int i=0, a, b; i<n; i++){
        scanf("%d%d", &a, &b);
        map[b][a]=true;
    }

    int cnt=0;
    for (int i=0, a, b; i<n; i++){
        scanf("%d%d", &a, &b);
        point[i]=Point(a, b);
    }sort(point, point+n);
    for (int i=0; i<n; i++){
        int a=point[i].x, b=point[i].y;
        bool ifbreak=false;
        for (int x=a-1; x>=0; x--){
            for (int y=b-1; y>=0; y--)
                if (map[y][x]) {cnt++; map[y][x]=false; ifbreak=true; break;}
            if (ifbreak) break;
        }
    }printf("%d\n", cnt);

    return 0;
}
