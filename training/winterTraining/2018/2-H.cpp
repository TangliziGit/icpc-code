#include <cstring>
#include <cstdio>
const int MAX=int(1e6);
char a[100+5];
int b, psize=0, primes[MAX+5];
void init(void){
    int isprime[MAX+5];
    memset(isprime, -1, sizeof(isprime));
    for (int i=2; i<=MAX; i++){
        if (isprime[i]){
            primes[psize++]=i;
            for (int k=2*i; k<=MAX; k+=i)
                isprime[k]=0;
        }
    }
}

inline int mod(const int &idx, const int &length){
    int ans=0;
    for (int i=0; i<length; i++)
        ans=(ans*10+a[i]-'0')%primes[idx];
    return ans;
}

int main(void){
    init();
    while (scanf("%s%d", a, &b)==2 && b){
        int length=strlen(a), flag=0;
        for (int idx=0; idx<psize && primes[idx]<b; idx++)
            if (!mod(idx, length)) {
                printf("BAD %d\n", primes[idx]);
                flag=1; break;
            }
        if (!flag) printf("GOOD\n");
    }

    return 0;
}
