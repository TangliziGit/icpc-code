#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef unsigned long long ULL;
int gcd(int a, int b){
    return (b==0)?a:gcd(b, a%b);
}

pair<ULL, ULL> solve(int n, int t){
    ULL res[2]={0}, _pow[60];
    _pow[0]=1;
    for (int i=1; i<60; i++) _pow[i]=_pow[i-1]*t;

    for (int i=1; i<=n; i++)
        res[0]+=_pow[gcd(n, i)];
    if (n%2) res[1]=n*_pow[(n+1)/2];
    else res[1]=(n/2)*(_pow[(n+2)/2]+_pow[n/2]);
    return make_pair(res[0]/n, (res[0]+res[1])/(2*n));
}

int main(void){
    int n, t;

    while (scanf("%d%d", &n, &t)==2){
        pair<ULL, ULL> res=solve(n, t);
        printf("%llu %llu\n", res.first, res.second);
    }

    return 0;
}
