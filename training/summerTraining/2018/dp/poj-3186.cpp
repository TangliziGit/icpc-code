#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=2e3+20;
int num[maxn], data[maxn][maxn], n;
int dp(int st, int end){
    if (st>end) return 0;
    if (st==end) return num[st]*n;
    if (data[st][end]>0) return data[st][end];
    return data[st][end]=max(dp(st+1, end)+num[st]*(n-end+st), dp(st, end-1)+num[end]*(n-end+st));
}

int main(void){
    while (scanf("%d", &n)==1 && n){
        memset(data, -1, sizeof(data));
        for (int i=0; i<n; i++) scanf("%d", &num[i]);
        printf("%d\n", dp(0, n-1));
    }

    return 0;
}
