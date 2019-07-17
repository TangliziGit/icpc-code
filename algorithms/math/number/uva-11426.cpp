#include <cstdio>
#include <cstring>
#include <ctime>
const int maxn=4e6+20;
long long phi[maxn], ans[maxn];
bool isprime[maxn];
void initPhi(void){
    memset(phi, 0, sizeof(phi));
    phi[1]=1;
    for (int i=2; i<maxn; i++) if (!phi[i])
        for (int j=i; j<maxn; j+=i){
            if (!phi[j]) phi[j]=j;
            phi[j]=phi[j]/i*(i-1);
        }
}

void initAns(void){
    for (int i=1; i<maxn; i++)
        for (int j=i+i; j<maxn; j+=i)
            ans[j]+=i*phi[j/i];

    for (int i=3; i<maxn; i++)
        ans[i]+=ans[i-1];
}

int main(void){
    int n;
    initPhi(); initAns();
    while (scanf("%d", &n)==1 && n)
        printf("%lld\n", ans[n]);

    return 0;
}
