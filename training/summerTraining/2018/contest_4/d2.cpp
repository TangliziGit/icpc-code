#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const long long mod=100000007;
const int maxn=1e7+20, maxp=1e5+20;
long long fact[maxn], pow2[maxn];//, inv[mod];
int n;

long long exgcd(long long a, long long b, long long &x, long long &y){
    if (b==0) {x=1; y=0; return a;}
    int gcd=exgcd(b, a%b, y, x);
    y-=(a/b)*x;
    return gcd;
}

long long inv(long long a){
    long long x, y, gcd=exgcd(a, mod, x, y);
    if (gcd==1) return (x%mod+mod)%mod;
    return -1;
}

void init(void){
    fact[0]=1;
    for (int i=1, ptr=1; i<maxn; i++)
        fact[i]=(fact[i-1]*i)%mod;
    pow2[0]=1;
    for (int i=1; i<maxn; i++)
        pow2[i]=(pow2[i-1]*2)%mod;
    printf("done\n");
    // printf("done");
    // inv[1]=1;
    // for (int i=2; i<mod; i++)
    //     inv[i]=(long long)(mod-mod/i)*inv[mod%i]%mod;
    // printf("done");
}

long long pow(long long x, int num){
    long long res=1;
    for (int i=0; i<num; i++) 
        res=(res*x)%mod;
    return res;
}

long long func(int n){
    if (n==1) return 1;
    if (n==2) return 18;
    if (n==3) return 132;
    return (pow2[n-4]*(pow(n, 4) + 6*pow(n, 3) + 3*pow(n, 2) - 2*n )%mod)%mod;
}
int main(void){
    init();
    for (int n=1; n<=maxn; n++){
        long long ans=0;
        for (int i=1; i<=n; i++){
            long long tmp, pow4=(((i*i)%mod)*((i*i)%mod))%mod;

            tmp=(pow4*fact[n])%mod;
            tmp=(tmp*inv(fact[i]))%mod;
            tmp=(tmp*inv(fact[n-i]))%mod;
            ans=(ans+tmp)%mod;
        }

        if (ans!=func(n))
            printf("%d: %lld %lld\n", n, ans, func(n));
        if ((n+1)%100000==0) printf("%d -\n", n);
    }

    return 0;
}

