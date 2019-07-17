#include <cstdio>
#include <cstring>
long long GCD(long long a, long long b){
    return (b==0)?a:GCD(b, a%b);
}

int main(void){
    int n;
    long long gcd=-1;

    scanf("%d", &n);
    for (int i=0; i<n; i++){
        long long a=0, b=0;
        scanf("%I64d%I64d", &a, &b);
        if (gcd==-1) gcd=a/GCD(a, b)*b;
        else gcd=GCD(gcd, a/GCD(a, b)*b);
    }
    if (gcd>1) printf("%I64d\n", gcd);
    else printf("-1\n");

    return 0;
}
