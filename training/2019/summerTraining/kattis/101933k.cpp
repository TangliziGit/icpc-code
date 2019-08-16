#include <cstdio>
typedef long long LL;
const int maxn=2500+20;
const LL mod=1e9+7;
LL frac[maxn];
int n, k;

void init(void){
    frac[0]=1;
    for (int i=1; i<maxn; i++) frac[i]=(frac[i-1]*i)%mod;
}

LL pow(LL x, LL n){
    LL cnt=x, res=1;
    for (int i=0; (1<<i)<=n; i++){
        if ((1<<i) & n) res=(res*cnt)%mod;
        cnt=(cnt*cnt)%mod;
    }return res;
}

LL inv(LL x){return pow(x, mod-2);}
LL C(LL a, LL b){return frac[b]*inv(frac[a])%mod*inv(frac[b-a])%mod;}

int main(void){
    int tmp;
    init();
    while (scanf("%d%d", &n, &k)==2){
        for (int i=0; i<n-1; i++) scanf("%d", &tmp);

        LL ans=0;
        for (int i=2; i<=k; i++){
            int sign=((k-i)%2==0)?1:-1;

            int tmp=C(i, k)*i%mod;
            tmp=(tmp*pow(i-1, n-1))%mod;
            ans=(ans+(sign*tmp+mod))%mod;
        }printf("%lld\n", ans);
    }

    return 0;
}
