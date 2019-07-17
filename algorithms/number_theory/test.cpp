#include <cstdio>
void exgcd(long long a, long long b,
        long long &gcd, long long &x, long long &y){
    if (b==0) {gcd=a; x=1; y=0;}
    else {exgcd(b, a%b, gcd, y, x); y-=x*(a/b);}
}

int main(void){
    long long x, y, n, m, l;

    while (scanf("%lld%lld%lld%lld%lld", &x, &y, &n, &m, &l)==5){
        long long a=m-n, b=-l, c=y-x, gcd;
        exgcd(a, b, gcd, x, y);

        if (c%gcd) printf("Impossible\n");
        else{
            a/=gcd; b/=gcd; c/=gcd;
            if (b<0) {b*=-1; x*=-1;}
            printf("%lld\n", (x%b+b)%b);
        }
    }

    return 0;
}
