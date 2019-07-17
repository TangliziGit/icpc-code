// Can judge_1 solve this?
// we have no test data for it :(

#include <cstdio>
const int max=10000;
long long num[max+5], n;
bool judge_1(void){
    long long mod=num[0]%num[1];

    if (n>=3) for (int i=2; mod!=0 && i<n; i++)
        mod=(mod*(num[i]%num[1]))%num[1];
    return mod==0;
}

long long gcd(long long a, long long b){
    return (b==0)?a:gcd(b, a%b);
}

bool judge(void){
    long long m=gcd(num[0], num[1]);

    if (n>=3) for (int i=2; m!=1 && i<n; i++)
        m=gcd(m, num[i]);
    return m==1;
}

int main(void){
    while (scanf("%lld", &n)==1 && n){
        for (int i=0; i<n; i++) scanf("%lld", &num[i]);

        if (judge()) printf("YES\n");
        else printf("NO\n");
    }

    return 0;
}
