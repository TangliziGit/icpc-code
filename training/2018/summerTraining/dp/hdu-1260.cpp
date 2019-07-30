#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int INF=0x3f3f3f3f;
int n, single[2000+20], couple[2000+20], data[2000+20];
int dp(int x){
    if (x>=n) return 0;
    if (data[x]) return data[x];
    return data[x]=min(single[x]+dp(x+1), couple[x]+dp(x+2));
}

int main(void){
    int T;

    scanf("%d", &T);
    while (T--){
        memset(data, 0, sizeof(data));
        scanf("%d", &n);
        for (int i=0; i<n; i++) scanf("%d", &single[i]);
        for (int i=0; i<n-1; i++) scanf("%d", &couple[i]);
        couple[n-1]=INF;

        int total=dp(0), hour=8+total/3600, min=(total%3600)/60, sec=total%60;
        if (hour/12) printf("%02d:%02d:%02d pm\n", hour%12, min, sec);
        else printf("%02d:%02d:%02d am\n", hour%12, min, sec);
    }

    return 0;
}
