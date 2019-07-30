#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int data[10000+20], pre[10000+20], maxidx=0;
int n=1, wei[10000+20], spd[10000+20];
void print(int x){
    if (x==0) return;
    print(pre[x]);
    printf("%d\n", x);
}

int dp(int x){
    if (data[x]) return data[x];

    for (int i=1; i<n; i++) if (i!=x)
        if (wei[i]<wei[x] && spd[i]>spd[x] && data[x]<dp(i)){
            data[x]=dp(i);
            pre[x]=i;
        }
    return ++data[x];
}

int main(void){
    memset(pre, 0, sizeof(pre));
    memset(data, 0, sizeof(data));

    while (scanf("%d%d", &wei[n], &spd[n])==2) n++;

    int maxidx=1;
    for (int i=1; i<=n; i++) if (dp(i)>dp(maxidx))
        maxidx=i;
    printf("%d\n", dp(maxidx));
    print(maxidx);

    return 0;
}
