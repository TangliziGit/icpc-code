#include <cstdio>
#include <cstring>
const int maxn=1e6;
int phi[maxn+5];
long long sum[maxn+5];
void initPhi(void){
    memset(phi, 0, sizeof(phi));
    phi[1]=1;
    for (int i=2; i<=maxn; i++) if (!phi[i])
        for (int j=i; j<=maxn; j+=i){
            if (!phi[j]) phi[j]=j;
            phi[j]=phi[j]/i*(i-1);
        }
}

void getSum(void){
    sum[1]=0;
    for (int i=2; i<=maxn; i++)
        sum[i]=sum[i-1]+phi[i];
}

int main(void){
    initPhi();
    getSum();
    int n;

    while (scanf("%d", &n)==1 && n)
        printf("%lld\n", sum[n]);

    return 0;
}
