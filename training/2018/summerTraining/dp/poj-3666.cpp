#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=2e3+20, INF=0x3f3f3f3f;
int n, num[maxn], sorted[maxn], data[maxn][maxn];
inline int rnum(int x, bool reverse){
    if (!reverse) return num[x];
    return num[n-x-1];
}

int dp(int x, int idx, bool reverse=false){
    if (x==0) return abs(rnum(x, reverse)-sorted[idx]);
    if (data[x][idx]>=0) return data[x][idx];

    data[x][idx]=INF;
    for (int i=0; i<=idx; i++) if (i==0 || sorted[i-1]!=sorted[i])
        data[x][idx]=min(data[x][idx], dp(x-1, i));
    return data[x][idx]+=abs(rnum(x, reverse)-sorted[idx]);
}

int main(void){
    scanf("%d", &n);
    for (int i=0; i<n; i++) scanf("%d", &num[i]);
    for (int i=0; i<n; i++) sorted[i]=num[i];
    sort(sorted, sorted+n);

    int ans=INF;
    memset(data, -1, sizeof(data));
    for (int i=0; i<n; i++) ans=min(ans, dp(n-1, i));
    memset(data, -1, sizeof(data));
    for (int i=0; i<n; i++) ans=min(ans, dp(n-1, i, true));
    printf("%d\n", ans);

    return 0;
}
