#include <cstdio>
#include <cstring>
const int maxn=1e6+200;
int primes[maxn+5], psize;
bool isprime[maxn+5];

void initPrime(void){
    memset(isprime, true, sizeof(isprime));
    for (int i=2; i<maxn; i++) if (isprime[i]){
        for (int j=i; j<=maxn; j+=i)
            isprime[j]=false;
        primes[psize++]=i;
    }
}

long long solve(long long n){
    long long sum=1;
    for (int i=0; primes[i]<=n && i<psize; i++) if (n%primes[i]==0){
        long long asum=1;
        while (n%primes[i]==0) n/=primes[i], asum++;
        sum*=asum;
        // printf("for %lld: %lld\n", primes[i], asum);
    }
    if (n>1) printf("%d--\n", n);
    return sum+((n>1)?sum:0);
}

int main(void){
    initPrime();
    int T;
    long long n, m;

    // scanf("%d", &T);
    // for (int tcnt=1; tcnt<=T; tcnt++){
    //     scanf("%lld%lld", &n, &m);

    //     if (m*m>=n){
    //         printf("Case %d: 0\n", tcnt);
    //         continue;
    //     }

    //     long long ans=solve(n)/2;
    //     for (int i=1; i<m; i++)
    //         if (n%i==0) ans--;
    //     printf("Case %d: %lld\n", tcnt, ans);
    // }
    for (int i=maxn; i<=1e12; i++){
        solve(i);
        if (i%10000==0) printf("i: %d\n", i);
    }

    return 0;
}
