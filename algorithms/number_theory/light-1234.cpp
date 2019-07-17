#include <cstdio>
const int maxn=1e6;
double h[maxn+5];
void init(void){
    h[0]=h[1]=0;
    for (int i=1, ptr=1; i<=1e8; i++){
        if (i%100==0) {ptr++; h[ptr]=h[ptr-1];}
        h[ptr]+=1/(double)i;
    }
}

double calc(int n){
    double sum=0;
    for (int i=(n/100)*100; i<=n; i++)
        if (i!=0) sum+=1/(double)i;
    return sum+h[n/100];
}

int main(void){
    init();
    int T, n;

    scanf("%d", &T);
    for (int cnt=1; cnt<=T; cnt++){
        scanf("%d", &n);
        // printf("%d %d--\n", (n/100)*100, n/100);
        printf("Case %d: %.10f\n", cnt, calc(n));
    }

    return 0;
}
