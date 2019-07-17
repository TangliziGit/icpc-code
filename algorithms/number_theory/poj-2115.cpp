#include <cstdio>
void exgcd(long long a, long long b, long long &d,
        long long &x, long long &y){
    if (b==0) {d=a; x=1; y=0;}
    else {exgcd(b, a%b, d, y, x); y-=x*(a/b);}
}

int main(void){
    long long A, B, C, K;

    while (scanf("%lld%lld%lld%lld", &A, &B, &C, &K)==4 && K){
        long long a=C, b=((long long)1<<K), c=B-A, x, y, gcd;
        exgcd(a, b, gcd, x, y);

        if (c%gcd) printf("FOREVER\n");
        else{
            a/=gcd; b/=gcd; c/=gcd;
            x*=c; y*=c;
            printf("%lld\n", (x%b+b)%b);
        }
    }

    return 0;
}
