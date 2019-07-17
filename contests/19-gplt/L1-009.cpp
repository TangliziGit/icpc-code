#include <cstdio>
#include <cstring>
typedef long long LL;
int n;

LL gcd(LL a, LL b){
    return (a%b==0)?(b):gcd(b, a%b);
}

int main(void){
    long long a=0, b=1;
    long long ta, tb;

    scanf("%d", &n);
    for (int i=0; i<n; i++){
        scanf("%lld/%lld", &ta, &tb);
        long long tg=gcd(ta, tb);
        ta/=tg; tb/=tg;

        a*=tb; ta*=b;
        b*=tb;
        a+=ta;

        long long g=gcd(a, b);
        a/=g; b/=g;
    }
    if (a/b==0)
        printf("%lld/%lld\n", a%b, b);
    else if (a%b==0)
        printf("%lld\n", a/b);
    else
        printf("%lld %lld/%lld\n", a/b, a%b, b);

    return 0;
}
