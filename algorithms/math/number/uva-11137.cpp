// This code must be wrong.

#include <cstdio>
#include <cstring>
const int maxn=10000+20;
long long data[maxn];
long long dp(int x){
    if (x==0) return 1; //?
    if (data[x]>=0) return data[x];
    printf("%d %lld\n", x, data[x]);

    data[x]=0;
    for (int i=1; i<=21 && x-i*i*i>=0; i++)
        data[x]+=dp(x-i*i*i);
    return data[x];
}

int main(void){
    memset(data, -1, sizeof(data));
    dp(maxn-10);
    int n;

    while (scanf("%d", &n)==1 && n){
        printf("%lld\n", data[n]);
    }

    return 0;
}
