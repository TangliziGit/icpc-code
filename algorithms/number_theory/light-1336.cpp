#include <cstdio>
#include <cmath>
const double eps=1e-8;

int main(void){
    int T;
    long long n;

    scanf("%d", &T);
    for (int cnt=1; cnt<=T; cnt++){
        scanf("%lld", &n);
        n=n-(long long)(sqrt(n)+eps)-(long long)(sqrt(n/2)+eps);
        printf("Case %d: %lld\n", cnt, n);
    }

    return 0;
}
