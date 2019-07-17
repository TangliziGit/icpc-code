#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=10000, maxsize=2000;
bool vis[maxn+5], isprime[maxn+5], isSquareFree[maxn+5];
int sum[maxn+5], primes[maxsize+5], psize;

void is_prime(void){
    psize=0;
    memset(isprime, -1, sizeof(isprime));
    for (int i=2; i<maxn; i++) if (isprime[i]){
        for (int j=i*2; j<maxn; j+=i) isprime[j]=false;
        primes[psize++]=i;
    }
}

void is_square_free(void){
    memset(isSquareFree, -1, sizeof(isSquareFree));
    for (int i=0; i<psize; i++) if (primes[i]*primes[i]<maxn && isSquareFree[primes[i]*primes[i]]){
        int pow=primes[i]*primes[i];
        for (int j=pow; j<maxn; j+=pow) isSquareFree[i]=false;
    }

    sum[0]=0;
    for (int i=1; i<maxn; i++) sum[i]=sum[i-1]+int(isSquareFree[i]);
}

int main(void){
    int n, m;

    is_prime();
    is_square_free();

    while (scanf("%d%d", &n, &m)==2 && (n || m)){
        if (n>m) swap(n, m);
        printf("%d\n", sum[m]-sum[n]);
        // for (int i=0; i<1000; i++) if (isSquareFree[i])
        //     printf("%d\n", i);
    }

    return 0;
}
