#include <cstdio>
#include <cstring>
const int maxn=1e7;
int phi[maxn+5];
void initPhi(void){
    memset(phi, 0, sizeof(phi));
    phi[1]=1;
    for (int i=2; i<=maxn; i++) if (!phi[i])
        for (int j=i; j<=maxn; j+=i){
            if (!phi[j]) phi[j]=j;
            phi[j]=phi[j]/i*(i-1);
        }
}

int main(void){
    initPhi();
    int n;

    scanf("%d", &n);
    for (int i=1; i<=n; i++)
        printf("%d: %d\n", i, phi[i]);

    return 0;
}
