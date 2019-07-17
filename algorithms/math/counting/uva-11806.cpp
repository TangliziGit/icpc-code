#include <cstdio>
#include <cstring>
const int maxn=20+5, maxk=500+20;;
const long long mod=1000007; // is not a prime.
int n, m, k;
long long C[maxk][maxk];
void init(void){
    memset(C, 0, sizeof(C));
    C[0][0]=1;
    for (int i=1; i<maxk; i++){
        C[i][0]=C[i][i]=1;
        for (int j=1; j<i; j++)
            C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
            // C[i][j]=(C[i][j-1]*(i-j+1)/j)%mod;
    }
}

int main(void){
    int T, kase=0;

    init();
    scanf("%d", &T);
    while (T--){
        scanf("%d%d%d", &n, &m, &k);

        long long ans=0;
        for (int cnt=0; cnt<16; cnt++){
            int _cnt=0, nn=n, mm=m;
            if (cnt&1) {nn--; _cnt++;}
            if (cnt&2) {nn--; _cnt++;}
            if (cnt&4) {mm--; _cnt++;}
            if (cnt&8) {mm--; _cnt++;}

            if (_cnt%2) ans=(ans+mod-C[nn*mm][k])%mod;
            else ans=(ans+C[nn*mm][k])%mod;
        }printf("Case %d: %lld\n", ++kase, ans);
    }

    return 0;
}
