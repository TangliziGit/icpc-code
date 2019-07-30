#include <cstdio>
#include <cmath>
const double pi=3.1415926, e=exp(1), k=0.5*log10(2*pi);
int solve(int n){
    return (int)(n*log10(n/e)+0.5*log10(n)+k);
}

int main(void){
    int n;
    scanf("%*d");
    while (scanf("%d", &n)==1 && n)
        printf("%d\n", solve(n)+1);

    return 0;
}
