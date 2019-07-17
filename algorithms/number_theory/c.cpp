#include <cmath>
#include <cstdio>
#include <cstring>
const int maxn=1e6+200;
int primes[maxn+5], psize;
bool isprime[maxn+5], vis[maxn+5];
void initPrime(void){
    memset(isprime, true, sizeof(isprime));
    isprime[1]=isprime[2]=true;

    for (int i=2; i<maxn; i++) if (isprime[i]){
        for (int j=i; j<maxn; j+=i){
            isprime[j]=false;
        }
        primes[psize++]=i;
    }
}

int main(void){
    initPrime();
    int T;
    long long a, b;

    scanf("%d", &T);
    for (int tcnt=1; tcnt<=T; tcnt++){
        scanf("%lld%lld", &a, &b);
        
        int cnt=0;
        long long end=sqrt(a)+0.5;
        memset(vis, 0, sizeof(vis)); // vis.clear();

        if (end*end>=a) end--;
        if (end*end==a) end--;
        for (long long i=b; i<=end; i++) if (!vis[i]){
            if (a%i==0) cnt++;
            for (int j=0; i*primes[j]<=end && j<psize; j++){
                long long num=i*primes[j];
                if (a%num==0) cnt++;
                vis[num]=true;
            }
        }
        printf("Case %d: %d\n", tcnt, cnt);
    }
    
    return 0;
}
