#include <cstdio>
long long search(int i, int n){
    long long x=1, y=n;
    while (x<y-1){
        long long mid=(long long)(x+y)/2;
        printf("%lld\n", mid);
        if (n/i>=mid) y=mid;
        else x=mid;
    }return y;
}

long long H(int n){
    long long sum=0;
    long long pre=n, ptr;

    for (int i=2; i<=n; i++){
        ptr=search(i, n);
        printf("%lld %d %d %d %d\n", ptr, n/ptr, n/(ptr-1), n/(ptr+1), i);
        if (n/ptr!=i) break;    // !!!!!!
        sum+=(pre-ptr)*(n/pre);
        // printf("--%d %d %d %lld\n", ptr, pre, n/ptr, sum);
        pre=ptr;
    }
    
    // printf("%lld\n", sum);
    for (int i=pre; i>0; i--)
        sum+=n/i;//printf("i%d\n", i), sum+=n/i;
    return sum;
}

int main(void){
    int T, n;

    scanf("%d", &T);
    for (int cnt=1; cnt<=T; cnt++){
        scanf("%d", &n);
        printf("Case %d: %lld\n", cnt, H(n));
    }
    
    return 0;
}
