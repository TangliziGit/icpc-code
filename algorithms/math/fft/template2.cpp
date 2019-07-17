#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <complex>
#define MAXN 1<<18
using namespace std;
const double PI=acos(-1.0);
const int DFT=1, IDFT=-1;
typedef complex<double> Complex;
Complex a[MAXN], b[MAXN];
int n, m, pos[MAXN];

int initFFT(int n, int m){
    int R, L=0;
    for (R=1; R<n+m+2; R<<=1, L++);
    memset(pos, 0, sizeof(pos));
    for (int i=0;i<R;i++) pos[i]=(pos[i>>1]>>1)|((i&1)<<(L-1));
    return R;
}

void FFT(Complex c[], int n, int mode){
    Complex wn,w,x,y;
    for (int i=0;i<n;i++)
        if (i<pos[i]) swap(c[i], c[pos[i]]);
    for (int i=1;i<n;i<<=1){
        wn=Complex(cos(PI/i), sin(PI/i)*mode);
        for (int p=i<<1,j=0;j<n;j+=p){
            w=Complex(1,0);
            for (int k=0;k<i;k++,w=w*wn){
                x=c[j+k];y=w*c[j+k+i];
                c[j+k]=x+y;c[j+k+i]=x-y;
            }
        }
    }
    if (mode==IDFT)
        for (int i=0;i<n;i++) c[i]/=(double)n;
    return ;
}

inline int read(){
    int tmp;
    scanf("%d", &tmp);
    return tmp;
}

int main(void){
    while (scanf("%d%d", &n, &m)==2){
        for (int i=0;i<=n;i++) a[i]=Complex(read(), 0);
        for (int i=0;i<=m;i++) b[i]=Complex(read(), 0);

        int len=initFFT(n, m);
        FFT(a, len, DFT); FFT(b, len, DFT);
        for (int i=0;i<len;i++) a[i]=a[i]*b[i];
        FFT(a, len, IDFT);
        for (int i=0; i<=n+m; i++)
            printf("%d ", (int)(a[i].real()+0.5));
        printf("\n");
    }
    return 0;
}
