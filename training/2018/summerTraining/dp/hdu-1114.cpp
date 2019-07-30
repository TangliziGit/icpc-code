#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int INF=0x3f3f3f3f;
int wei[500+20], pri[500+20], data[10000+20], n;
int dp(int x){
    if (x==0) return 0;
    if (data[x]) return data[x];

    data[x]=INF;
    for (int i=0; i<n; i++) if (wei[i]<=x && dp(x-wei[i])<INF)
        data[x]=min(data[x], dp(x-wei[i])+pri[i]);
    return data[x];
}

int main(void){
    int tmp, weight, T;

    scanf("%d", &T);
    while (T--){
        memset(data, 0, sizeof(data));
        scanf("%d%d%d", &tmp, &weight, &n);
        for (int i=0; i<n; i++) scanf("%d%d", &pri[i], &wei[i]);

        if (dp(weight-tmp)>=INF) printf("This is impossible.\n");
        else printf("The minimum amount of money in the piggy-bank is %d.\n", dp(weight-tmp));
    }

    return 0;
}
