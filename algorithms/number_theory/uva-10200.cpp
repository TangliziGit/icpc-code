#include <cstdio>
#include <cmath>
const double eps=1e-6;
int sum[int(1e4)+15];
bool isprime(const long long &i){
    long long n=i*i+i+41, size=sqrt(n)+1;
    for (int mod=2; mod!=n && mod<=size; mod++)
        if (n%mod==0) return false;
    return true;
}

void init(void){
    sum[0]=1;
    for (int i=0; i<=int(1e4); i++)
        if (isprime(i)) sum[i+1]=sum[i]+1;
        else sum[i+1]=sum[i];
}

int main(void){
    int a, b;
    init();

    while (scanf("%d%d", &a, &b)==2)
        printf("%.2f\n", 100*(sum[b+1]-sum[a])/(double)(b-a+1)+eps);

    return 0;
}
