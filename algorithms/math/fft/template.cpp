#include <cstdio>
#include <cstring>
#include <complex>
using namespace std;
const double PI=acos(-1.0);
const int maxn=1e5+20;
const int DFT=1, IDFT=-1;
typedef complex<double> cp;
int pos[maxn];
int initFFT(int n, int m){
    int len, sum=n+m+2, tmp=0;
    for (len=1; len<sum; len<<=1, tmp++);
    // for (int i=0; i<len; i++)
    //    pos[i]=(pos[i>>1]>>1)|((i&1)<<(tmp-1));
    for (int i=0; i<len; i++)
        pos[i]=(pos[i>>1]>>1)|((i&1)<<(tmp-1));
        // pos[i]=(pos[i>>1]>>1)|((i&1)<<(tmp-1));
    return len;
}
void FFT(cp a[], int len, int mode){
    cp wn, w, x, y;
    for (int i=0; i<len; i++)
        if (i<pos[i]) swap(a[i], a[pos[i]]);
    for (int i=1; i<len; i<<=1){
        wn=cp(cos(PI/i), sin(PI/i)*mode);
        for (int p=i<<1, j=0; j<len; j+=p){
            w=cp(1, 0);
            for (int k=0; k<i; k++, w=w*wn){
                x=a[j+k]; y=w*a[j+k+i];
                a[j+k]=x+y; a[j+k+i]=x-y;
            }
        }
    }
    if (mode==IDFT) for (int i=0; i<len; i++)
        a[i]/=(double)len;
}

int main(void){
    int n, m;

    while (scanf("%d%d", &n, &m)==2 && n+m){
        int tmp;
        cp a[maxn], b[maxn], c[maxn];
        for (int i=0; i<=n; i++){
            scanf("%d", &tmp);
            a[i]=cp(tmp, 0);
        }
        for (int i=0; i<=n; i++){
            scanf("%d", &tmp);
            b[i]=cp(tmp, 0);
        }

        int len=initFFT(n, m);
        FFT(a, len, DFT); FFT(b, len, DFT);
        for (int i=0; i<len; i++) c[i]=a[i]*b[i];
        FFT(c, len, IDFT);

        for (int i=0; i<=n+m; i++)
            printf("%d ", int(c[i].real()+0.5));
        printf("\n");
    }

    return 0;
}
