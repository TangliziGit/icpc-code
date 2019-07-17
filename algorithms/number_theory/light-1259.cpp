#include <cmath>
#include <cstdio>
#include <cstring>
const int maxn=1e7, maxp=7e5;
bool isprime[maxn+5];
int primes[maxp+5], psize;

void initPrime(void){
    memset(isprime, true, sizeof(isprime));
    for (int i=2; i<=maxn; i++) if (isprime[i]){
        for (int j=i*2; j<=maxn; j+=i)
            isprime[j]=false;
        primes[psize++]=i;
    }
}

int solve(int n){
    int cnt=0, end=n/2;
    for (int i=0; i<psize && primes[i]<=end; i++)
        if (isprime[n-primes[i]]) cnt++;
    return cnt;
}

int main(void){
    initPrime();
    int T, n;

    scanf("%d", &T);
    for (int tcnt=1; tcnt<=T; tcnt++){
        scanf("%d", &n);
        printf("Case %d: %d\n", tcnt, solve(n));
    }

    return 0;
}
