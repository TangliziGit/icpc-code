#include <cstdio>
#include <cstring>
const int maxn=1e7+20;
const int mod=1e8+7;
int pow2[maxn];
void init(void){
    pow2[0]=1;
    for (int i=1; i<maxn; i++)
        pow2[i]=(pow2[i-1]*2)%mod;
    // printf("done\n");
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
    return ((pow2[n-4]*(pow(n, 4) + 6*pow(n, 3) + 3*pow(n, 2) - 2*n )%mod)%mod+mod)%mod;
}

int main(void){
    long long n;

    init();
    while (scanf("%lld", &n)==1 && n)
        printf("%lld\n", func(n));

    return 0;
}
