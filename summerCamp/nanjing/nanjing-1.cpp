#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxlen = 210;
const int INF = 0x3f3f3f3f;
char a[maxlen], b[maxlen];
int dat[maxlen][maxlen];

int dp(int x, int y) {
    if (x==-1 && y==-1) return 0;
    if (x<0 || y<0) return INF;
    if (dat[x][y]>=0) return dat[x][y];

    dat[x][y] = INF;
    dat[x][y] = min(dat[x][y], dp(x-1, y-1) + (a[x]!=b[y]));
    dat[x][y] = min(dat[x][y], dp(x, y-1) + 1);
    dat[x][y] = min(dat[x][y], dp(x-1, y) + 1);
    return dat[x][y];
}

int main(void) {
    scanf("%s%s", a, b);

    int alen = strlen(a), blen = strlen(b);
    for (int i=0; i<alen; i++)
        for (int j=0; j<blen; j++) dat[i][j] = -1; // INF;
            
    printf("%d\n", dp(alen-1, blen-1));

    return 0;
}
