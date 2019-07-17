#include <cstdio>
#include <cstring>
using namespace std;
const int maxp=1e4+20;
int inv[maxp], frac[maxp], n, k, p;
void init(){
    inv[1]=1; frac[0]=1; frac[1]=1;
    for (int i=2; i<p; i++){
        inv[i]=(p-p/i)*inv[p%i]%p;
        frac[i]=(frac[i-1]*i)%p;
    }
}

int C(int n, int k){
    return (frac[n]*inv[frac[k]]*inv[frac[n-k]])%p;
}

int ans(int n, int k){
    // printf("%d %d\n", n, k);
    if (k==0) return 1;
    return (C(n%p, k%p)*ans(n/p, k/p))%p;
}

int main(void){
    int T=0;
    while (scanf("%d%d%d", &n, &k, &p)==3){
        init();
        if ((n%2 && k>=n/2+1) || (n%2==0 && k>=n/2))
            printf("Case #%d: %d\n", ++T, (ans(n+1, n-k)+k)%p);
        else
            printf("Case #%d: %d\n", ++T, (ans(n+1, k)+n-k)%p);
    }

    return 0;
}
