#include <cstdio>
#include <cstring>
long long solve(int n){
    long long ans=0;
    for (int i=1; i<=n; i++)
        ans+=n/i;
    return ans;
}

int main(void){
    int n;
    while (scanf("%d", &n)==1){
        printf("%lld\n", solve(n));
    }
    
    return 0;
}
