#include <cstdio>
const int maxn=1000+20;
int x[maxn], _y1[maxn], y2[maxn];
int n;

int main(void){
    scanf("%d", &n);
    for (int i=0; i<n; i++) scanf("%d%d%d", &x[i], &_y1[i], &y2[i]);
    int ymin=_y1[0], ymax=y2[0];
    int imin=0, imax=0;
    for (int i=0; i<n; i++){
        if (_y1[i]<ymin){
            ymin=_y1[i];
            imin=i;
        }
        if (y2[i]>ymax){
            ymax=y2[i];
            imax=i;
        }
    }
    printf("%d %d %d %d\n", x[imin], ymin, x[imax], ymax);

    return 0;
}
