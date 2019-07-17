#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=100+20;
const int INF=1e9;
int c[maxn], n;
int data[maxn][maxn];
int dp(int l, int r){
    if (l>r) return 0;
    if (l==r) return c[l-1]*c[l]*c[l+1];
    if (data[l][r]>=0) return data[l][r];

    data[l][r]=INF;
    for (int i=l; i<=r; i++)
        data[l][r]=min(data[l][r], dp(l, i-1)+dp(i+1, r)+c[l-1]*c[i]*c[r+1]);
    return data[l][r];
}

int main(void){
    while (scanf("%d", &n)==1 && n){
        for (int i=0; i<n; i++) scanf("%d", &c[i]);
        memset(data, -1, sizeof(data));

        printf("%d\n", dp(1, n-2));
    }

    return 0;
}
