#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxm=1e3+20;
struct Interval{
    int x, y, eff;
    bool operator < (const Interval &a) const{
        return x<a.x;
    }
}inter[maxm];
int n, m, r, data[maxm];
int dp(int idx){
    if (idx>=m) return 0;
    if (data[idx]) return data[idx];

    data[idx]=inter[idx].eff;
    int lim=inter[idx].y+r;
    for (int i=idx+1; i<m; i++)
        if (lim<inter[i].x) data[idx]=max(data[idx], dp(i)+inter[idx].eff);
    return data[idx]=max(dp(idx+1), data[idx]);
}

int main(void){
    memset(data, 0, sizeof(data));
    scanf("%d%d%d", &n, &m, &r);
    for (int i=0; i<m; i++)
        scanf("%d%d%d", &inter[i].x, &inter[i].y, &inter[i].eff);
    sort(inter, inter+m);
    printf("%d\n", dp(0));

    return 0;
}
