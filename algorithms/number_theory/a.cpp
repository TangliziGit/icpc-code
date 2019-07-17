#include <cstring>
#include <cstdio>
const int maxn=2e6;
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
    int T;
    initPhi(); phi[1]=0;

    scanf("%d\n", &T);
    for (int cnt=1; cnt<=T; cnt++){
        int n, num;
        long long sum=0;
        scanf("%d", &n);
        for (int i=0; i<n; i++){
            scanf("%d", &num);
            for (int k=num; k<=maxn; k++)
                if (phi[k]>=num) {sum+=k; break;}
        }
        printf("Case %d: %lld Xukha\n", cnt, sum);
    }

    return 0;
}
