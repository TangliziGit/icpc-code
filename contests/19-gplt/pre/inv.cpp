#include <cstdio>
#include <cstring>
using namespace std;
const int mod=10007, maxn=mod+20;
int inv[maxn];

void getInv(){
    inv[1]=1;
    for (int i=2; i<mod; i++)
        inv[i]=(long long)(mod-mod/i)*inv[mod%i]%mod;
}

int exgcd(int a, int b, int &x, int &y){
    if (b==0) {x=1; y=0; return a;}
    int gcd=exgcd(b, a%b, y, x);
    y-=(a/b)*x;
    return gcd;
}

int _inv(int a, int mod){
    int x, y, gcd=exgcd(a, mod, x, y);
    if (gcd==1) return (x%mod+mod)%mod;
    return -1;
}

int main(void){
    getInv();
    for (int i=2; i<mod; i++)
        if (i*_inv(i, mod)%mod!=1) printf("warn %d\n", i);
    printf("pass\n");

    return 0;
}
