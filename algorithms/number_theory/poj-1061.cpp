#include <cstdio>
#include <algorithm>
using namespace std;
void exgcd(long long a, long long b, long long &d, long long &x, long long &y){
    if (b==0){d=a; x=1; y=0;}
    else {exgcd(b, a%b, d, y, x); y-=x*(a/b);}
}

int main(void){
    long long x, y, m, n, l;

    while (scanf("%lld%lld%lld%lld%lld", &x, &y, &m, &n, &l)==5 && l){
        if (m>n){swap(n, m); swap(x, y);}
        long long a=n-m, b=l, c=-(y-x), tx, ty, gcd;
        exgcd(a, b, gcd, tx, ty);

        // printf("%lld %lld %lld gcd%lld tx%lld ty%lld\n", a, b, c, gcd, tx, ty);
        if (c%gcd) printf("Impossible\n");
        else {
            a/=gcd; b/=gcd; c/=gcd;
            tx*=c;
            printf("%lld\n", (tx%b+b)%b);
        }
    }

    return 0;
}
