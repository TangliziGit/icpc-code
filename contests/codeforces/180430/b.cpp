#include <cstdio>
long long n, m, k;
void func(long long rest){
    if (rest%(m-1)==0) printf("%lld %lld\n", n-rest/(m-1), ((rest/(m-1))%2==0)?(2):(m));// func(rest);
    else{
        long long y=rest%(m-1), x=rest/(m-1);
        if (x%2==0) printf("%lld %lld\n", n-x, y+2);
        else printf("%lld %lld\n", n-x, m-(y));
    }
}

int main(void){
    scanf("%lld%lld%lld", &n, &m ,&k);
    if (k+1<=n) printf("%lld 1\n", k+1);
    else if (k==n) printf("%lld 2\n", n);
    else if (m>2) func(k-n);
    else if (m==2) printf("%lld %d\n", 2*n-k, 2);

    return 0;
}
